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
}

Coronium::~Coronium()

{
    if (context)
        delete context;
    if (trans)
        delete trans;
    if (loader)
        delete loader;
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

/**
 * @brief exports all the asm and pcode instructions found within the range
 *        [addr, addr + len)
 *
 * This method relies upon AssemblyRaw::dump and PcodeRaw::dump. Those two
 * methods perform the actual decoding and hold the storage of assembly and
 * pcode data. This method combines the side effects of both those methods.
 *
 * NOTE: Different len's may result in the same number of instructions decoded.
 * This is because some lengths might end in the middle of an instruction. In
 * such situations the decoder cannot discern the instruction and so drops it.
 *
 * @param[in] addr Start address.
 * @param[in] len  Number of bytes to decode.
 * @return A vector of Instructions containing raw assembly and raw pcode.
 */
auto
Coronium::dump (uintb addr, int4 len) -> std::vector<Instruction>

{
    std::vector<Instruction> result;

    AssemblyRaw asm_emit;
    PcodeRaw pcode_emit;

    Address pos (trans->getDefaultCodeSpace(), addr);
    Address finish (trans->getDefaultCodeSpace(), addr + len);

    int4 length;

    while (pos < finish) {
        trans->printAssembly (asm_emit, pos);
        length = trans->oneInstruction (pcode_emit, pos);
        auto insn = Instruction (asm_emit, pcode_emit);
        insn.size = length;
        result.push_back (insn);
        pos = pos + length;
    }
    return result;
}

// PUBLIC METHODS -----------------------------------------------------------------
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
Coronium::load (uintb baseaddr, uint1* imgbuffer, int4 imgsize) -> void

{
    std::string slafilepath = _cpu_dir + "/" + ldefs["slafile"];
    Element* sleighroot = docstorage.openDocument (slafilepath)->getRoot();
    docstorage.registerTag (sleighroot);
    context = new ContextInternal();
    loader = new BinaryRaw (baseaddr, imgbuffer, imgsize);
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

/*
 *
 * AssemblyRaw
 *
 */

auto
AssemblyRaw::dump (const Address& addr, const string& mnem, const string& body)-> void

{
    this->address = addr;
    this->mnemonic = mnem;
    this->body = body;
}

/*
 *
 * PcodeRaw
 *
 */

auto
PcodeRaw::dump (const Address& addr, OpCode opc, VarnodeData* outvar, VarnodeData* vars, int4 isize) -> void

{
    this->addr = addr;
    this->opc = opc;
    if (outvar != (VarnodeData*)0) {
        this->hasOutvar = true;
        this->outvar = *outvar;
    }
    for (auto i = 0; i != isize; ++i) {
        this->vars.push_back (vars[i]);
    }
}

// |EOF|--------------------------------------------------------------------------|
