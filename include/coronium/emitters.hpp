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
#include <memory>
/* local (ghidra) */
#include "translate.hh"
#include "pcoderaw.hh"
#include "address.hh"
#include "opcodes.hh"
#include "opbehavior.hh"

namespace coronium {

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * @class PcodeRaw
 * @brief Used to get raw pcode.
 */
class PcodeRaw : public PcodeEmit {
    friend class Instruction;
private:
    void print_varnode (std::ostream&, VarnodeData&);
    // ----------------------------------------
    std::vector<PcodeOpRaw*> pcodeOps;
    vector<VarnodeData*> vnodes_cache;
    std::vector<OpBehavior*>& pcode_behaviors;
public:
    PcodeRaw (std::vector<OpBehavior*>& behavior);
    PcodeRaw (PcodeRaw const& other) = default;
    ~PcodeRaw();
    void clear_cache (void);
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
struct Instruction
{
    AssemblyRaw assembly;
    PcodeRaw pcode;
    int4 size;
    Instruction (AssemblyRaw assem, PcodeRaw&& rawpc, int4 sz);
    Instruction (Instruction const& other);
    Instruction (Instruction&& other) noexcept;
    ~Instruction();
};

}

#endif /* EMITTERS_H */
