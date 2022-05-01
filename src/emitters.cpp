/**
 * @file emitters.cpp
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

#include "../include/coronium/emitters.hpp"
#include <cstdlib>

using namespace coronium;

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * PcodeRaw
 *
 */
PcodeRaw::PcodeRaw(std::vector<OpBehavior *> &behavior) : pcode_behaviors(behavior)

{}

PcodeRaw::~PcodeRaw()

{
}

// The "Instruction" type will manage the lifetime of PcodeRaw
// (i.e., do not put this into the destructor).
auto
PcodeRaw::clear_cache (void) -> void

{
    for (auto &i : pcodeOps) {
        if (i) {
            delete i;
            i = nullptr;
        }
    }
    for (auto &i : vnodes_cache) {
        if (i) {
            delete i;
            i = nullptr;
        }
    }

}

auto
PcodeRaw::dump (const Address& addr, OpCode opc, VarnodeData* outvar, VarnodeData* vars, int4 isize) -> void

{
    PcodeOpRaw *raw = new PcodeOpRaw();

    raw->setBehavior (pcode_behaviors[opc]);
    raw->setSeqNum(addr, pcodeOps.size());
    if (outvar) {
        auto *out = new VarnodeData();
        *out = *outvar;
        vnodes_cache.push_back(out);
        raw->setOutput(out);
    } else
        raw->setOutput(nullptr);

    for (auto i = 0; i != isize; ++i) {
        auto *in = new VarnodeData();
        *in = vars[i];
        raw->addInput(in);
        vnodes_cache.push_back(in);
    }
    pcodeOps.push_back(raw);
}

// --------------------------------------------------------------------------------
auto
PcodeRaw::print_varnode (std::ostream& s, VarnodeData& vdata) -> void

{
    const Translate* trans = vdata.space->getTrans ();
    string spacename = vdata.space->getName ();

    if (spacename == "unique") {
        s << '(' << vdata.space->getName()
          << ',';
        vdata.space->printOffset (s, vdata.offset);
        s  << ',' << dec << vdata.size << ')';
        return;
    }

    if (spacename == "register") {
        s << trans->getRegisterName (vdata.space, vdata.offset, vdata.size);
    } else {
        vdata.space->printOffset (s, vdata.offset);
    }
}

// --------------------------------------------------------------------------------
auto
PcodeRaw::print (std::ostream& s) -> void

{
    for (auto inst : pcodeOps)
    {
        VarnodeData* out = inst->getOutput();
        if (out) {
            print_varnode (s, *out);
            s << " = ";
        }

        std::string op = get_opname (inst->getOpcode());
        s << op << ' ';

        if (op == "STORE") {
            s << "ram[";
            print_varnode (s, *inst->getInput(1)); // skip over invar 0.
            s << "] = ";
        }

        if (op == "LOAD") {
            s << "ram[";
            print_varnode (s, *inst->getInput(1)); // skip over invar 0.
            s << "]";
        }

        for (int i = (op == "STORE" || op == "LOAD") ? 2 : 0;
             i != inst->numInput(); ++i)
        {
            print_varnode (s, *inst->getInput(i) );
            if (i != inst->numInput() - 1)
                s << ", ";
        }
        s << "\n";
    }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Instruction
 *
 */
Instruction::Instruction (AssemblyRaw assem, PcodeRaw&& rawpc, int4 sz)
    : pcode (rawpc.pcode_behaviors)
{
    size = sz;
    assembly = assem;

    /* PcodeRaw */
    pcode.pcodeOps = std::vector<PcodeOpRaw*> (rawpc.pcodeOps.size(), (PcodeOpRaw*)0);
    for (auto i = 0; i != rawpc.pcodeOps.size(); ++i) {
        pcode.pcodeOps[i] = rawpc.pcodeOps[i];
        rawpc.pcodeOps[i] = nullptr;
    }

    pcode.vnodes_cache = std::vector<VarnodeData*> (rawpc.vnodes_cache.size(), (VarnodeData*)0);
    for (auto i = 0; i != rawpc.vnodes_cache.size(); ++i) {
         pcode.vnodes_cache[i] = rawpc.vnodes_cache[i];
         rawpc.vnodes_cache[i] = nullptr;
    }
}

/*
 * MOVE CONSTRUCTOR
 */
Instruction::Instruction (Instruction&& other) noexcept
    : pcode (other.pcode.pcode_behaviors)
{
    size = other.size;
    assembly = other.assembly;

    /* PcodeRaw */
    pcode.pcodeOps = std::vector<PcodeOpRaw*> (other.pcode.pcodeOps.size(), (PcodeOpRaw*)0);
    for (auto i = 0; i != other.pcode.pcodeOps.size(); ++i) {
        pcode.pcodeOps[i] = other.pcode.pcodeOps[i];
        other.pcode.pcodeOps[i] = nullptr;
    }
    other.pcode.pcodeOps.clear();

    pcode.vnodes_cache = std::vector<VarnodeData*> (other.pcode.vnodes_cache.size(), (VarnodeData*)0);
    for (auto i = 0; i != other.pcode.vnodes_cache.size(); ++i) {
        pcode.vnodes_cache[i] = other.pcode.vnodes_cache[i];
        other.pcode.vnodes_cache[i] = nullptr;
    }
    other.pcode.vnodes_cache.clear();
}

/*
 * COPY CONSTRUCTOR
 */
Instruction::Instruction (Instruction const& other)
    : pcode (other.pcode.pcode_behaviors)
{
    size = other.size;
    assembly = other.assembly;

    /* PcodeRaw */
    pcode.pcodeOps = std::vector<PcodeOpRaw*> (other.pcode.pcodeOps.size(), (PcodeOpRaw*)0);
    for (auto i = 0; i != other.pcode.pcodeOps.size(); ++i) {
        auto* rawOp = new PcodeOpRaw();
        *rawOp = *other.pcode.pcodeOps[i];
        pcode.pcodeOps[i] = rawOp;
    }

    pcode.vnodes_cache = std::vector<VarnodeData*> (other.pcode.vnodes_cache.size(), (VarnodeData*)0);
    for (auto i = 0; i != other.pcode.vnodes_cache.size(); ++i) {
        auto* vn = new VarnodeData();
        *vn = *other.pcode.vnodes_cache[i];
        pcode.vnodes_cache[i] = vn;
    }
}


Instruction::~Instruction()

{
    pcode.clear_cache();
}
