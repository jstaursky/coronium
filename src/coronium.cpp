/* ###
 * @file coronium.cpp
 * @author Joe Staursky
 *
 * @section LICENSE
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "coronium.hpp"
#include <cstring>
#include <cstdio>  // perror(), fopen(), fputs() and fclose()
#include <cstdlib> // EXIT_* macros */

namespace coronium {

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
 * CPU
 *
 */

// CONSTRUCTORS/DESTRUCTORS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CPU::CPU (std::string id)
{
    _lang_id = id;

    // id's are of the form <cpu>:<endianess>:<size>:<variant>
    _cpu = id.substr (0, id.find (":"));

    char const* env = getenv ("SLA_DIR");
    if (env) {
        coronium::cpus_directory = new char[strlen (env) + 1];
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

CPU::~CPU()
{
    if (context)
        delete context;
    if (trans)
        delete trans;
    if (loader)
        delete loader;
}

// PRIVATE METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
auto
CPU::importContexts (ContextDatabase* cdb) -> void
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

// PUBLIC METHODS -----------------------------------------------------------------
auto
CPU::load (const std::string& f, LoadImage* load) -> void
{
    std::string slafilepath = _cpu_dir + "/" + ldefs["slafile"];
    Element* sleighroot = docstorage.openDocument (slafilepath)->getRoot();
    docstorage.registerTag (sleighroot);
    context = new ContextInternal();      // Create a processor context

    if (!load) {
        loader = new DefaultLoadImage (f);
    }

    trans = new Sleigh (loader, context); // Instantiate the translator
    trans->initialize (docstorage);

    if (!load) {
        dynamic_cast<DefaultLoadImage*> (loader)->attachToSpace (trans->getDefaultCodeSpace());
    }

    importContexts (context);
}

/*
 *
 * DefaultLoadImage
 *
 */

// CONSTRUCTORS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
DefaultLoadImage::DefaultLoadImage (const string& filename) : LoadImage (filename)
{
    type = BINARY_FILE;
    vma = 0;
    spaceid = (AddrSpace*)0;
    binaryFile = fopen (filename.c_str(), "r+b");
    if (!binaryFile) {
        std::string err = "unable to open file" + filename;
        perror (err.c_str());
        exit (EXIT_FAILURE);
    }
    fseek (binaryFile, 0L, SEEK_END);
    bsize = ftell (binaryFile);
    fseek (binaryFile, 0L, SEEK_SET);
}

DefaultLoadImage::DefaultLoadImage (uintb addr, uint1* buffer, int4 sz) : LoadImage ("nofile")
{
    type = BINARY_BUFFER;
    vma = addr;
    binaryBuffer = buffer;
    bsize = sz;
}

DefaultLoadImage::~DefaultLoadImage ()
{
    if (type == BINARY_FILE) {
        fclose (binaryFile);
    }
}

// PUBLIC METHODS -----------------------------------------------------------------
auto
DefaultLoadImage::adjustVma (long adjust) -> void

{
    adjust = AddrSpace::addressToByte (adjust, spaceid->getWordSize());
    vma += adjust;
}

// --------------------------------------------------------------------------------
auto
DefaultLoadImage::loadFill (uint1* ptr, int4 len, const Address& addr) -> void

{
    // Get the offset relative to the base address.
    uintb curaddr = addr.getOffset() - vma;
    uintb readlen;
    int4 rest = len;

    if (curaddr >= bsize) {
        // initial address not within binary.
        goto ERROR;
    }
    // ensure that the amount read is within the addr space bounds of the binary.
    readlen = (curaddr + len > bsize) ? bsize - curaddr : len;

    if (this->type == BINARY_FILE) {
        fseek (binaryFile, curaddr, SEEK_SET);
        curaddr += fread (ptr, sizeof (uint1), readlen, binaryFile);
        rest -= readlen;
    }

    if (this->type == BINARY_BUFFER) {
        memcpy (ptr, &binaryBuffer[curaddr], readlen);
        curaddr += readlen;
        rest -= readlen;
    }

    if (curaddr >= bsize) {
        memset (ptr + len - rest, 0, rest);
    }

ERROR:
    // wait to error out until we are unable to read any bytes.
    if (len == rest) {
        ostringstream errmsg;
        errmsg << "Unable to load " << dec << len << " bytes at " << addr.getShortcut();
        addr.printRaw (errmsg);
        std::cout << errmsg.str() << std::endl;
        exit (EXIT_FAILURE);
    }
}


// |EOF|--------------------------------------------------------------------------|
}
