/**
 * @file coronium.cpp
 * Copyright (C) 2022 Joe Staursky
 *
 * @section LICENSE
 *
 * This file is part of coronium.
 *
 * coronium is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * coronium is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * coronium. If not, see <https://www.gnu.org/licenses/>.
 */

#include <cstring>
#include <cstdio>  // perror(), fopen(), fputs() and fclose()
#include <cstdlib> // EXIT_* macros

#include "coronium.hpp"

using namespace coronium;

// Global variable 'cpus_directory' is defined in this file.
namespace coronium {
char const* cpus_directory;
}

/*
 *
 * static functions
 *
 */
static auto
getFiles (std::string filetype, std::string dirname, std::vector<std::string>* files) -> void

{
    DIR* dir = opendir (dirname.c_str ());
    struct dirent* dp;
    std::string path;

    if (!dir)
        return;

    while (dp = readdir (dir), dp != nullptr) {
        auto entry = std::string (dp->d_name);

        if (entry == "." || entry == "..")
            continue;

        path = (dirname + "/" + entry);

        if (entry.rfind (filetype) != std::string::npos &&
            entry.rfind (filetype) == (entry.length () - std::string (filetype).length ()))
            files->push_back (path);

        getFiles (filetype, path, files);
    }
    closedir (dir);
}

// --------------------------------------------------------------------------------
static auto
findFile (std::string fname, std::string dir) -> std::string

{
    std::vector<std::string> filelist;
    auto ext = fname.find ("."); // get file extension.
    getFiles (fname.substr (ext), dir, &filelist);
    for (auto& i : filelist) {
        std::string f = i.substr (i.find_last_of ("/\\") + 1);
        // Need comparison to be case insensitive.
        for (auto& c : fname)
            c = std::tolower (c);
        for (auto& c : f)
            c = std::tolower (c);
        if (f == fname) {
            return std::string (i);
        }
    }
    return "";
}

/*
 *
 * Coronium
 *
 */

// CONSTRUCTORS/DESTRUCTORS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Coronium::Coronium (std::string id)

{
    setCpuDirectory ();         // initialize global 'cpus_directory' to default value

    _lang_id = id;              // the 'id' field found in an ldef file.

    // id's are of the form <cpu>:<endianess>:<size>:<variant>
    _cpu = id.substr (0, id.find (":"));

    char const* env = getenv ("SLA_DIR");
    if (env) {
        cpus_directory = new char[strlen (env) + 1];
        memcpy ((void*)cpus_directory, (void*)env, strlen (env) + 1);
    }

    // find language definitions ("ldefs").
    std::vector<std::string> filelist;
    getFiles (".ldefs", cpus_directory, &filelist);
    for (auto& f : filelist) {
        DocumentStorage doc;
        auto root = doc.openDocument (f)->getRoot ();
        for (auto el : root->getChildren()) {
            if (_lang_id == el->getAttributeValue ("id")) {
                _cpu_dir = f.substr (0, f.find_last_of ("/\\"));
                for (auto i = 0; i != el->getNumAttributes (); ++i) {
                    ldefs[el->getAttributeName (i)] = el->getAttributeValue (i);
                }
            }
        }
    }
    OpBehavior::registerInstructions(pcode_behaviors, trans);
}

Coronium::~Coronium()

{
    if (context)
        delete context;
    if (trans)
        delete trans;
    if (loader)
        delete loader;

    for (auto &i : pcode_behaviors) {
        delete i;
        i = nullptr;
    }
}

// PRIVATE METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * @brief This function is necessary to prevent duplicate symbols error.
 *
 * global variable 'cpus_directory' cannot be set in the header file when there are
 * multiple cpp files that include it. Since coronium.hpp is a compile time header this
 * makes it complicated to set globals to compile time constants. This is the current work
 * around (set compile-time constant as the default value in header).
 */
auto
Coronium::setCpuDirectory (std::string dir) -> void

{
    cpus_directory = new char[dir.length() + 1];
    memcpy((void*)cpus_directory, (void*)dir.c_str(), dir.length() + 1);
}

// --------------------------------------------------------------------------------
auto
Coronium::importContexts (ContextDatabase* cdb) -> void

{
    DocumentStorage docs;
    auto pspec = findFile (ldefs["processorspec"], _cpu_dir);
    auto e = docs.openDocument (pspec)->getRoot();

    std::unordered_map<std::string, std::string> ctx;
    std::function<void (Element*&, std::unordered_map<std::string, std::string>&)> conf_ctx;
    conf_ctx = [&conf_ctx] (Element*& el, std::unordered_map<std::string, std::string>& results) -> void {
        if (!el)
        {
            return;
        }
        for (auto child : el->getChildren())
        {
            if ((el->getName() == "context_set") && (child->getName() == "set")) {
                auto attr = child->getAttributeValue ("name");
                auto val = child->getAttributeValue ("val");
                results[attr] = val;
            } else
                conf_ctx (child, results);
        }
    };

    conf_ctx (e, ctx);
    for (auto p : ctx) {
        try {
            context->setVariableDefault (p.first, std::stoi (p.second));
        } catch (LowlevelError& e) {
            std::cerr << "Warning: " << e.explain << std::endl;
        }
    }
}

// PUBLIC METHODS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
auto
Coronium::load (const std::string& f) -> void

{
    std::string slafilepath = _cpu_dir + "/" + ldefs["slafile"];
    Element* sleighroot = docstorage.openDocument (slafilepath)->getRoot();
    docstorage.registerTag (sleighroot);
    loader = new Binary (f, "default");
    context = new ContextInternal();      // Create a processor context
    trans = new Sleigh (loader, context); // Instantiate the translator

    trans->initialize (docstorage);
    dynamic_cast<Binary*> (loader)->attachToSpace (trans->getDefaultCodeSpace());
    importContexts (context);
}

// --------------------------------------------------------------------------------
auto
Coronium::load (uint1* imgbuffer, int4 imgsize) -> void

{
    std::string slafilepath = _cpu_dir + "/" + ldefs["slafile"];
    Element* sleighroot = docstorage.openDocument (slafilepath)->getRoot();
    docstorage.registerTag (sleighroot);
    context = new ContextInternal();
    loader = new BinaryRaw (imgbuffer, imgsize);
    trans = new Sleigh (loader, context);

    trans->initialize (docstorage);
    dynamic_cast<BinaryRaw*> (loader)->attachToSpace (trans->getDefaultCodeSpace());
    importContexts (context);
}

// --------------------------------------------------------------------------------
auto
Coronium::getBinaryImage() const -> Binary*

{
    auto* ret = dynamic_cast<Binary*> (loader);
    if (ret) return ret;
    else {
        std::cerr << "binary did not originate from a file" << std::endl;
        exit (EXIT_FAILURE);
    }
}

// --------------------------------------------------------------------------------
auto
Coronium::getBinaryRawImage() const -> BinaryRaw*

{
    auto* ret = dynamic_cast<BinaryRaw*> (loader);
    if (ret) return ret;
    else {
        std::cerr << "binary originates from a file" << std::endl;
        exit (EXIT_FAILURE);
    }
}

/**
 * @brief exports ninsns ("n instructions") asm and pcode instructions.
 *
 *
 * This method relies upon AssemblyRaw::dump and PcodeRaw::dump. Those two
 * methods perform the actual decoding and hold the storage of assembly and
 * pcode data. This method combines the side effects of both those methods.
 *
 * @param[in] addr Start address.
 * @param[in] ninsns Number of instructions to decode.
 * @return A vector of Instructions containing raw assembly and raw pcode.
 */
auto
Coronium::disassemble (Address addr, uint4 ninsns) -> std::vector<Instruction>

{
    std::vector<Instruction> result;

    while (result.size() != ninsns) {
        AssemblyRaw asm_emit;
        PcodeRaw pcode_emit (this->pcode_behaviors);
        trans->printAssembly (asm_emit, addr);
        int4 length = trans->oneInstruction (pcode_emit, addr);
        result.push_back (std::move (Instruction (asm_emit, std::move(pcode_emit), length)));
        addr = addr + length;
    }
    return result;
}

// --------------------------------------------------------------------------------
auto
Coronium::dump (Range rng) -> std::vector<Instruction>

{
    std::vector<Instruction> result;

    Address pos = rng.getFirstAddr ();
    Address finish = rng.getLastAddr ();
    while (pos < finish) {
        AssemblyRaw asm_emit;
        PcodeRaw pcode_emit (this->pcode_behaviors);
        trans->printAssembly (asm_emit, pos);
        int4 length = trans->oneInstruction (pcode_emit, pos);
        result.push_back (std::move (Instruction (asm_emit, std::move(pcode_emit), length)));
        pos = pos + length;
    }
    return result;
}
// |EOF|--------------------------------------------------------------------------|
