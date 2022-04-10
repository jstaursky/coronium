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

int main (int argc, char** argv)

{
    // For fun try playing other cpu interpretations of bytes. Try:
    // 8085:LE:16:default
    uint1 payload[] = {
        0x66, 0x68, 0xeb, 0x05, 0x31, 0xc0,
        0x74, 0xfa, 0xe8, 0xff, 0xc0, 0x67, 0x48
    };

    auto coro = coronium::Coronium ("x86:LE:32:default");

    std::cout << coro.getArchType () << std::endl;
    coro.load("testfile");
//    coro.load (0x00000000, payload, sizeof (payload));

    coronium::Binary* bin = coro.getBinaryImage ();

    auto number_of_insns = 3;
    std::vector<coronium::Instruction> insn = coro.disassemble (0x00001040, number_of_insns);

//    std::vector<coronium::Instruction> insn = bin->dump (&coro, 0x00001040, 3);

//    coronium::BinaryRaw* bin = coro.getBinaryRawImage ();
//    std::vector<coronium::Instruction> insn = bin->dump (&coro, 0x00000000, 3);

    for (auto i : insn) {
        std::cout << i.assembly.mnemonic << " "
                  << i.assembly.body
                  << std::endl;
    }

}
