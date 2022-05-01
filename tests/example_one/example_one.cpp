/**
 * @file example_one.cpp
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

#include <coronium/coronium.hpp>
#include <coronium/types.h>
#include <coronium/loadimage.hh>
#include <coronium/sleigh.hh>
#include <coronium/emulate.hh>

#include <iostream>

using namespace coronium;
using namespace std;

int main (int argc, char** argv)

{
    // For fun try playing other cpu interpretations of bytes. Try:
    // 8085:LE:16:default
    uint1 payload[] = {
        0x66, 0x68, 0xeb, 0x05, 0x31, 0xc0,
        0x74, 0xfa, 0xe8, 0xff, 0xc0, 0x67, 0x48
    };

    // auto coro_ex1 = Coronium ("x86:LE:32:default");

    // std::cout << coro_ex1.getArchType () << endl;
    // coro_ex1.load ("testfile");

    // Binary* bin = coro_ex1.getBinaryImage ();

    // auto number_of_insns = 3;
    // vector<Instruction> insn = coro_ex1.disassemble (bin->getAddress (0x00001040), number_of_insns);
    // for (auto i : insn)
    // {
    //     cout << i.assembly.mnemonic << " "
    //          << i.assembly.body << endl;

    // }

    // cout << "----------------------------------------\n";

    // vector<Instruction> instr = coro_ex1.dump (bin->getAddressRange (0x00001040, 0x00001040 + 0x10));
    // for (auto i : instr)
    // {
    //     cout << i.assembly.mnemonic << " "
    //          << i.assembly.body
    //          << endl;
    // }

    cout << "----------------------------------------\n";

    {
        auto coro = Coronium ("x86:LE:32:default");
        coro.load (payload, sizeof (payload));
        coronium::BinaryRaw* bin = coro.getBinaryRawImage ();
        bin->setBaseAddress(0x00000000);

        auto min = 0x00000000;
        auto max = 0x00000000 + sizeof(payload);
        vector<Instruction> insn = coro.dump (bin->getAddressRange (min, max));

        for (auto i : insn)
        {
            cout << i.assembly.mnemonic << " "
                 << i.assembly.body
                 << endl;
            i.pcode.print(cout);
            cout << endl;
        }

    }
    cout << "----------------------------------------\n";

    // {
    //     static uint1 tmp[] = { 0x55 };
    //     auto coro = Coronium ("x86:LE:32:default");
    //     coro.load (tmp, sizeof (tmp));
    //     coronium::BinaryRaw* bin = coro.getBinaryRawImage ();
    //     bin->setBaseAddress(0x00000000);

    //     auto min = 0x00000000;
    //     auto max = 0x00000000 + sizeof(tmp);
    //     vector<Instruction> insn = coro.dump (bin->getAddressRange (min, max));
    //     for (auto i : insn)
    //     {
    //         cout << i.assembly.mnemonic << " "
    //              << i.assembly.body
    //              << endl;
    //         i.pcode.print_pcode (cout);
    //     }



    // }

}
