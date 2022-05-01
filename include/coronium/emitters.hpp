/**
 * @file emitters.hpp
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

#ifndef EMITTERS_H
#define EMITTERS_H

#include <vector>
#include <iostream>
#include <string>
/* local (ghidra) */
#include "translate.hh"
#include "pcoderaw.hh"
#include "address.hh"
#include "opcodes.hh"

namespace coronium {

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * @class PcodeRaw
 * @brief Used to get raw pcode.
 */
class PcodeRaw : public PcodeEmit {
private:
//    PcodeRaw(std::vector<OpBehavior *> *behavior);
    struct PcodeStatement {
        PcodeStatement (Address adr, OpCode op) : addr(adr), opc(op) {}
        Address addr;
        OpCode opc;
        std::vector<VarnodeData> invars;
        VarnodeData outvar;
        bool hasOutvar = false;
    };
    std::vector<PcodeStatement> pcode;
    void print_varnode (std::ostream&, VarnodeData&);
public:
    PcodeRaw() = default;
    void dump (const Address& addr, OpCode opc, VarnodeData* outvar, VarnodeData* vars, int4 isize) override;
    void print (std::ostream&);
};

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * @class AssemblyRaw
 * @brief Used to get assembly.
 */
class AssemblyRaw : public AssemblyEmit {
public:
    Address address;
    std::string mnemonic;
    std::string body;
    void dump (const Address& addr, const std::string& mnem, const std::string& body) override;
};

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * @class Instruction
 * @brief All content relating to a single instruction.
 */
struct Instruction {
    AssemblyRaw assembly;
    PcodeRaw pcode;
    int4 size;                  // length of the instruction.
    Instruction (AssemblyRaw _asm, PcodeRaw _pcode) : assembly (_asm), pcode (_pcode)
    {};
};

}

#endif /* EMITTERS_H */
