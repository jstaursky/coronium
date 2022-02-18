#include <coronium/coronium.hpp>
#include <coronium/loadimage.hh>
#include <coronium/loadimage_bfd.hh>
#include <coronium/globalcontext.hh>
#include <coronium/sleigh.hh>
#include <iostream>


class Binary
{
    LoadImageBfd* loader;
    ContextDatabase* context;
    Translate* trans;
    DocumentStorage docstorage;
    Element* sleighroot;
    coronium::CPU* cpu;
public:
    Binary (const std::string& fname, const std::string& target)
    {
        loader = new LoadImageBfd (fname, target);
        loader->open();       // Load the executable from file
        context = new ContextInternal();   // Create a processor context
        trans = new Sleigh (loader, context); // Instantiate the translator
    }
    void initialize (const std::string& arch)
    {
        cpu = new coronium::CPU (arch);
        sleighroot = docstorage.openDocument (*cpu)->getRoot();
        docstorage.registerTag (sleighroot);
        trans->initialize (docstorage); // Initialize the translator
        loader->attachToSpace (trans->getDefaultCodeSpace());
    }
    AddrSpace* getSpace() { return trans->getDefaultCodeSpace(); }
    int4 printAssembly (AssemblyEmit& asm_, const Address& adr)
    {
        return trans->printAssembly (asm_, adr);
    }

    coronium::CPU foo() { return *cpu; }
};

class AssemblyRaw : public AssemblyEmit
{
public:
    virtual void dump (const Address& addr, const string& mnem, const string& body)
    {
        addr.printRaw (cout);
        cout << ": " << mnem << ' ' << body << endl;
    }
};

int main (int argc, char* argv[])
{
    std::cout << "NOTE: to run this properly you need to provide an x86 binary as an arg.\n"
              << "you may/likely also need to update the 'vaddr' variable inside the source "
              << "to the start of the .text section of your binary.\n\n";

    Binary bin_code (argv[1], "default");
    bin_code.initialize ("x86");

    uintm vaddr = 0x000004f0;
    AssemblyEmit* assememit = new AssemblyRaw();
    Address addr (bin_code.getSpace(), vaddr);

    int4 length;
    length = bin_code.printAssembly (*assememit, addr);
    addr = addr + length;
    length = bin_code.printAssembly (*assememit, addr);
    addr = addr + length;
    length = bin_code.printAssembly (*assememit, addr);

    auto cpu = bin_code.foo();

    for (auto i : cpu.context_docs) {
        std::cout << "file = " << i.filename << std::endl;
        for (auto itr = i.ctx.begin(); itr != i.ctx.end(); ++itr) {
            std::cout << "var = " << itr->first << "\nval = " << itr->second << std::endl;
        }
    }

    return 0;
}
