#include <coronium/coronium.hpp>
#include <coronium/loadimage.hh>
#include <coronium/loadimage_bfd.hh>
#include <coronium/globalcontext.hh>
#include <coronium/sleigh.hh>
#include <coronium/emulate.hh>
#include <iostream>

// WORK IN PROGRESS
//
//

class Binary;

class AssemblyRaw : public AssemblyEmit
{
public:
    virtual void dump (const Address& addr, const string& mnem, const string& body)
    {
        addr.printRaw (cout);
        cout << ": " << mnem << ' ' << body << endl;
    }
};

class EmulateBfd
{
public:
    Binary* binary;
    EmulatePcodeCache *emulator;
    EmulateBfd(Binary* bin) : binary(bin){};

    void doEmulation();
};

// A callback that terminates the emulation
class TerminateCallBack : public BreakCallBack {
public:
    virtual bool addressCallback(const Address &addr);
};

bool TerminateCallBack::addressCallback(const Address &addr)

{
    emulate->setHalt(true);

    return true;
}


// A callback that terminates the emulation
class runCallBack : public BreakCallBack {
public:
    virtual bool addressCallback(const Address &addr);
};

bool runCallBack::addressCallback(const Address &addr)

{
    MemoryState *mem = static_cast<EmulateMemory *>(emulate)->getMemoryState();
    AddrSpace *ram = mem->getTranslate()->getSpaceByName("ram");

//    emulate->setExecuteAddress(Address(ram, ));

    return true;
}


class Binary
{
    friend class EmulateBfd;
public:
    LoadImageBfd* loader;
    ContextDatabase* context;
    Translate* trans;
    DocumentStorage docstorage;
    Element* sleighroot;
    EmulateBfd* emu;
    coronium::CPU* cpu;

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
        emu = new EmulateBfd(this);
    }
    AddrSpace* getSpace() { return trans->getDefaultCodeSpace(); }
    int4 printAssembly (AssemblyEmit& asm_, const Address& adr)
    {
        return trans->printAssembly (asm_, adr);
    }
};

auto EmulateBfd::doEmulation() -> void
{
    MemoryImage loadmemory(binary->trans->getDefaultCodeSpace(),8,4096, binary->loader);
    MemoryPageOverlay ramstate(binary->trans->getDefaultCodeSpace(),8,4096,&loadmemory);
    MemoryHashOverlay registerstate(binary->trans->getSpaceByName("register"),8,4096,4096,(MemoryBank *)0);
    MemoryHashOverlay tmpstate(binary->trans->getUniqueSpace(),8,4096,4096,(MemoryBank *)0);

    MemoryState memstate(binary->trans);	// Instantiate the memory state object
    memstate.setMemoryBank(&ramstate);
    memstate.setMemoryBank(&registerstate);
    memstate.setMemoryBank(&tmpstate);

    BreakTableCallBack breaktable(binary->trans); // Set up the callback object

    emulator = new EmulatePcodeCache(binary->trans, &memstate, &breaktable);
    memstate.setValue("ESP",0xbffffffc);
    emulator->setExecuteAddress(Address(binary->trans->getDefaultCodeSpace(),0x000004f0));  // Initial execution address

    TerminateCallBack terminatecallback;
    breaktable.registerAddressCallback(Address(binary->trans->getDefaultCodeSpace(),0x80482c8),&terminatecallback);

    emulator->setHalt(false);


    AssemblyRaw assememit;
    Address addr;
    for(;;) {
        addr = emulator->getExecuteAddress();
        auto len = binary->trans->printAssembly(assememit,addr);
        addr = addr + len;
        emulator->executeInstruction();
    }

}



int main (int argc, char* argv[])
{
    std::cout << "NOTE: to run this properly you need to provide an x86 binary as an arg.\n"
              << "you may/likely also need to update the 'vaddr' variable inside the source "
              << "to the start of the .text section of your binary.\n\n";

    Binary bin_code (argv[1], "default");
    bin_code.initialize ("x86");

    EmulateBfd emu(&bin_code);
    emu.doEmulation();

    // uintm vaddr = 0x000004f0;
    // AssemblyEmit* assememit = new AssemblyRaw();
    // Address addr (bin_code.getSpace(), vaddr);


    // int4 length;
    // length = bin_code.printAssembly (*assememit, addr);
    // addr = addr + length;
    // length = bin_code.printAssembly (*assememit, addr);
    // addr = addr + length;
    // length = bin_code.printAssembly (*assememit, addr);

    // auto cpu = bin_code.foo();

    // for (auto i : cpu.context_docs) {
    //     std::cout << "file = " << i.filename << std::endl;
    //     for (auto itr = i.ctx.begin(); itr != i.ctx.end(); ++itr) {
    //         std::cout << "var = " << itr->first << "\nval = " << itr->second << std::endl;
    //     }
    // }

    return 0;
}
