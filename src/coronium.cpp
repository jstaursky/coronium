#include "coronium.hpp"

namespace coronium {

static auto
get_file_paths (std::string filetype, std::string dirname, std::vector<std::string>* files) -> void

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

        get_file_paths (filetype, path, files);
    }
    closedir (dir);
}

// --------------------------------------------------------------------------------
auto
find_file (std::string fname, std::string dir) -> std::string

{
    std::vector<std::string> filelist;
    auto ext = fname.find ("."); // get file extension.
    get_file_paths (fname.substr (ext), dir, &filelist);
    for (auto& i : filelist) {
        auto f = i.substr(i.find_last_of("/\\") + 1);
        if (f == fname) {
            return std::string (i);
        }
    }
    return "";
}



// CONSTRUCTORS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CPU::CPU (std::string id)
{
    _lang_id = id;
    // id's are of the form <cpu>:<endianess>:<size>:<variant>
    _cpu = id.substr(0, id.find(":"));
    std::transform(_cpu.begin(), _cpu.end(), _cpu.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    auto cpu_definitions = findCpuManifest (_cpu);
    size_t delimiter = cpu_definitions.find_last_of ("/\\");
    _cpu_dir = cpu_definitions.substr (0, delimiter);

    setLanguageDefs ();
}

// PRIVATE METHODS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
auto
CPU::setLanguageDefs () -> void

{
    std::vector<std::unordered_map<std::string, std::string>> results;

    DocumentStorage docs;
    auto f = find_file (_cpu + ".ldefs", _cpu_dir);
    Element* root = docs.openDocument (f)->getRoot ();


    auto get_langdefs = [&]() -> std::vector<std::unordered_map<std::string, std::string>> {
        for (auto el : root->getChildren ()) {
            std::unordered_map<std::string, std::string> ldef;
            for (auto i = 0; i != el->getNumAttributes (); ++i) {
                ldef[el->getAttributeName (i)] = el->getAttributeValue (i);
            }
            results.push_back (ldef);
        }
        return results;
    };

    // configure processor language definitions.
    for (auto defs : get_langdefs ())
    {
        if (defs["id"] == _lang_id) {
            for (auto s : defs)
                ldefs[s.first] = s.second;
            break;
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
auto
CPU::setContexts (ContextDatabase* cdb) -> void
{
    DocumentStorage docs;
    auto pspec = find_file(ldefs["processorspec"], _cpu_dir);
    std::cout << "found " << pspec << std::endl;
    auto e = docs.openDocument (pspec)->getRoot();

    std::unordered_map<std::string, std::string> ctx;
    std::function<void(Element*&, std::unordered_map<std::string, std::string>&)> conf_ctx;
    conf_ctx = [&conf_ctx](Element*& el, std::unordered_map<std::string, std::string>& results) -> void
    {
        if (!el) {
            return;
        }
        for (auto child : el->getChildren())
        {
            if ((el->getName() == "context_set") && (child->getName() == "set")) {
                auto attr = child->getAttributeValue("name");
                auto val = child->getAttributeValue("val");
                results[attr] = val;
            } else
                conf_ctx (child, results);
        }
    };

    conf_ctx (e, ctx);
    for (auto p : ctx) {
        try {
            context->setVariableDefault(p.first, std::stoi(p.second));
        } catch (LowlevelError& e) {
            std::cout << "Warning: " << e.explain << std::endl;
        }
    }
}

// PUBLIC METHODS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
auto
CPU::load(const std::string &f) -> void
{
    std::string slafilepath = _cpu_dir + "/" + ldefs["slafile"];

    loader = new DefaultLoadImage(this, f);
    loader->open();
    context = new ContextInternal();      // Create a processor context
    trans = new Sleigh (loader, context); // Instantiate the translator

    sleighroot = docstorage.openDocument (slafilepath)->getRoot();
    docstorage.registerTag (sleighroot);
    trans->initialize (docstorage);
    setContexts (context);
    loader->attachToSpace(trans->getDefaultCodeSpace());
}


} // END OF NAMESPACE
