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

/*
 *
 * PcodeRaw
 *
 */
auto
PcodeRaw::dump (const Address& addr, OpCode opc, VarnodeData* outvar, VarnodeData* vars, int4 isize) -> void

{
    PcodeStatement pcode_stmt (addr, opc);
    if (outvar != (VarnodeData*)0) {
        pcode_stmt.hasOutvar = true;
        pcode_stmt.outvar = *outvar;
    }
    for (auto i = 0; i != isize; ++i) {
        pcode_stmt.invars.push_back (vars[i]);
    }
    pcode.push_back(pcode_stmt);
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
    for (auto stmt : pcode)
    {
        if (stmt.hasOutvar) {
            print_varnode (s, stmt.outvar);
            s << " = ";
        }
        string op = get_opname (stmt.opc);
        s << op << ' ';
        bool isSpecial = (op == "STORE" || op == "LOAD");

        if (op == "STORE") {
            s << "ram[";
            print_varnode (s, stmt.invars[1]); // skip over invar 0.
            s << "] = ";
        }

        if (op == "LOAD") {
            s << "ram[";
            print_varnode (s, stmt.invars[1]); // skip over invar 0.
            s << "]";
        }

        for (auto i = isSpecial ? 2 : 0; i != stmt.invars.size(); ++i) {
            print_varnode (s, stmt.invars[i]);
            if (i != stmt.invars.size() - 1)
                s << ", ";
        }
        s << "\n";
    }
}
