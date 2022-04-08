/**
 * @file loadbinary.cpp
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

#include <iostream>

#include "coronium.hpp"
#include "../include/coronium/loadbinary.hpp"

using namespace coronium;

/*
 *
 * BinaryRaw
 *
 */

BinaryRaw::BinaryRaw (uintb addr, uint1* buffer, int4 sz) : LoadImage ("nofile")

{
    vma = addr;
    binaryBuffer = buffer;
    binsize = sz;
}

BinaryRaw::~BinaryRaw ()

{

}

// PUBLIC METHODS -----------------------------------------------------------------
auto
BinaryRaw::adjustVma (long adjust) -> void

{
    adjust = AddrSpace::addressToByte (adjust, spaceid->getWordSize());
    vma += adjust;
}

// --------------------------------------------------------------------------------
auto
BinaryRaw::loadFill (uint1* ptr, int4 len, const Address& addr) -> void

{
    // Get the offset relative to the base address.
    uintb curaddr = addr.getOffset() - vma;
    uintb readlen;
    int4 rest = len;

    if (curaddr >= binsize) {
        // initial address not within binary.
        goto ERROR;
    }
    // ensure that the amount read is within the addr space bounds of the binary.
    readlen = (curaddr + len > binsize) ? binsize - curaddr : len;

    memcpy (ptr, &binaryBuffer[curaddr], readlen);
    curaddr += readlen;
    rest -= readlen;

    if (curaddr >= binsize) {
        memset (ptr + len - rest, 0, rest);
    }

ERROR:
    // wait to error out until we are unable to read any bytes.
    if (len == rest) {
        ostringstream errmsg;
        errmsg << "Unable to load " << dec << len << " bytes at " << addr.getShortcut();
        addr.printRaw (errmsg);
        std::cout << errmsg.str() << std::endl;
        exit (EXIT_FAILURE);
    }
}

// --------------------------------------------------------------------------------
auto
BinaryRaw::dump (Coronium* coro, uintb addr, int4 len) -> std::vector<Instruction>

{
    return coro->dump (addr, len);
}

/*
 *
 * Binary
 *
 */

Binary::Binary (const string& f, const string& t) : LoadImageBfd (f, t)

{
    this->open();
}

// --------------------------------------------------------------------------------
auto
Binary::dump (Coronium* coro, uintb addr, int4 len) -> std::vector<Instruction>

{
    return coro->dump (addr, len);
}

