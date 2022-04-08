/**
 * @file loadbinary.hpp
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

#ifndef BINARYLOADER_H
#define BINARYLOADER_H

#include "loadimage_bfd.hh"

namespace coronium {

// forward declare(s)
class Coronium;
class Instruction;

/**
 * @class BinaryRaw
 * @brief LoadImage class for dealing with raw hex buffers.
 */
class BinaryRaw : public LoadImage {
private:
    uint1* binaryBuffer = nullptr;
    int4 binsize;               // size of binary
    AddrSpace* spaceid;
    uintb vma;                  // virtual memory base address.
public:
    BinaryRaw (uintb addr, uint1* buffer, int4 sz); // For opening raw buffers
    BinaryRaw (BinaryRaw* other) = delete;
    virtual ~BinaryRaw ();
    auto attachToSpace (AddrSpace* id) -> void { spaceid = id; }
    void adjustVma (long adjust) override;
    std::string getArchType (void) const override { return "unknown"; };
    void loadFill (uint1* ptr, int4 size, const Address& addr) override;
    auto dump (Coronium* coro, uintb addr, int4 len = 1) -> std::vector<Instruction>;
};

/**
 * @class Binary
 * @brief LoadImage class for dealing with Binary Files.
 */
class Binary : public LoadImageBfd {
public:
    Binary (const std::string& f, const std::string& t);
    Binary (Binary* other) = delete; // shallow copies issue w/ thebfd.
    virtual ~Binary() {}
    auto dump (Coronium* coro, uintb addr, int4 len = 1) -> std::vector<Instruction>;
};


}


#endif /* BINARYLOADER_H */
