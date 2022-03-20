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
        context->setVariableDefault("addrsize",2);
        context->setVariableDefault("opsize",1);
        context->setVariableDefault("bit64",1);
        context->setVariableDefault("longMode",1);

        loader->attachToSpace (trans->getDefaultCodeSpace());
        emu = new EmulateBfd(this);
    }
    AddrSpace* getSpace() { return trans->getDefaultCodeSpace(); }
    int4 printAssembly (AssemblyEmit& asm_, const Address& adr)
    {
        return trans->printAssembly (asm_, adr);
    }
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

class keepalivecallback : public BreakCallBack {
public:
  virtual bool addressCallback(const Address &addr);
};

bool keepalivecallback::addressCallback(const Address &addr)
{
    // MemoryState *mem = static_cast<EmulateMemory *>(emulate)->getMemoryState();
    // uint1 buffer[256];
    // uint4 esp = mem->getValue("ESP");
    // AddrSpace *ram = mem->getTranslate()->getSpaceByName("ram");
 
    // uint4 param1 = mem->getValue(ram,esp+4,4);
    // mem->getChunk(buffer,ram,param1,255);
 
    // cout << (char *)&buffer << endl;
 
    // uint4 returnaddr = mem->getValue(ram,esp,4);
    // mem->setValue("ESP",esp+8);
    // emulate->setExecuteAddress(Address(ram,returnaddr));
 
    // MemoryState *mem = static_cast<EmulateMemory *>(emulate)->getMemoryState();
    // uint1 buffer[256];
    // uint4 esp = mem->getValue("RIP");
    // AddrSpace *ram = mem->getTranslate()->getSpaceByName("ram");
 
    // uint4 param1 = mem->getValue(ram,esp,4);
    // mem->getChunk(buffer,ram,param1,1);
 
    // cout << (char *)&buffer << endl;
 
    // uint4 returnaddr = mem->getValue(ram,esp,4);
    // mem->setValue("ESP",esp+8);
    // emulate->setExecuteAddress(Address(ram,returnaddr));
 
    return true;                        // This replaces the indicated instruction
}

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

    BreakTableCallBack breaktable(binary->trans);
    EmulatePcodeCache emulator(binary->trans,&memstate,&breaktable);
 
    keepalivecallback keepalivecallback;
    TerminateCallBack terminatecallback;
    breaktable.registerAddressCallback(Address(binary->trans->getDefaultCodeSpace(),0x00001040),&keepalivecallback);
    breaktable.registerAddressCallback(Address(binary->trans->getDefaultCodeSpace(),0x000011c4),&terminatecallback);

    emulator.setExecuteAddress(Address(binary->trans->getDefaultCodeSpace(),0x00001040));  // Initial execution address

    AssemblyRaw assememit;
    Address addr = emulator.getExecuteAddress();
    emulator.setHalt(false);
    do {
        auto len = binary->trans->printAssembly(assememit,addr);
        emulator.executeInstruction();
        addr = addr + len;
    } while(!emulator.getHalt());

}



int main (int argc, char* argv[])
{
    std::cout << "NOTE: to run this properly you need to provide an x86 binary as an arg.\n"
              << "you may/likely also need to update the 'vaddr' variable inside the source "
              << "to the start of the .text section of your binary.\n\n";

    Binary bin_code (argv[1], "default");
    bin_code.initialize ("x86-64");

    EmulateBfd emu(&bin_code);
    emu.doEmulation();

    // uintm vaddr = 0x00001040;
    // AssemblyEmit* assememit = new AssemblyRaw();
    // Address addr (bin_code.getSpace(), vaddr);


    // int4 length;
    // length = bin_code.printAssembly (*assememit, addr);
    // addr = addr + length;
    // length = bin_code.printAssembly (*assememit, addr);
    // addr = addr + length;
    // length = bin_code.printAssembly (*assememit, addr);

    // auto cpu = *bin_code.cpu;

    // for (auto i : cpu.context_docs) {
    //     std::cout << "file = " << i.filename << std::endl;
    //     for (auto itr = i.ctx.begin(); itr != i.ctx.end(); ++itr) {
    //         std::cout << "var = " << itr->first << "\nval = " << itr->second << std::endl;
    //     }
    // }

    return 0;
}
