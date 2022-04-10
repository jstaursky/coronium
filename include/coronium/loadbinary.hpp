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

#include "loadimage.hh"

// bfd.h requires PACKAGE/PACKAGE_VERSION to be defined
// https://sourceware.org/bugzilla/show_bug.cgi?id=14243

#ifndef PACKAGE
  #define PACKAGE
  #define __LOADBINARY_BFD__DEFINED_PACKAGE
#endif

#ifndef PACKAGE_VERSION
  #define PACKAGE_VERSION
  #define __LOADBINARY_BFD__DEFINED_PACKAGE_VERSION
#endif

#include <bfd.h>

#ifdef __LOADBINARY_BFD__DEFINED_PACKAGE
  #undef PACKAGE
  #undef __LOADBINARY_BFD__DEFINED_PACKAGE
#endif

#ifdef __LOADBINARY_BFD__DEFINED_PACKAGE_VERSION
  #undef PACKAGE_VERSION
  #undef __LOADBINARY_BFD__DEFINED_PACKAGE_VERSION
#endif

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
    // pure virtual  overrides ----------------
    void loadFill(uint1 *ptr,int4 size,const Address &addr) override;
    std::string getArchType (void) const override { return "unknown"; };
    void adjustVma(long adjust) override;
    // ----------------------------------------
    auto attachToSpace (AddrSpace* id) -> void { spaceid = id; }
    Range getAddressRange (uintb faddr, uintb laddr);
};

/**
 * @class Binary
 * @brief LoadImage class for dealing with Binary Files.
 *
 * Originally based on the LoadImageBfd.
 */
class Binary : public LoadImage {
private:
    static int4 bfdinit;		// Is the library (globally) initialized
    string target;              // File format (supported by BFD)
    bfd *thebfd;
    AddrSpace *spaceid;
    // caching --------------------------------
    uintb bufoffset;            // Starting offset of byte buffer
    uint4 bufsize;              // Number of bytes in the buffer
    uint1 *buffer;              // The actual buffer
    // ----------------------------------------
    asection *findSection(uintb offset,uintb &ssize) const;
public:
    Binary (const std::string& f, const std::string& t);
    Binary (Binary* other) = delete; // shallow copies issue w/ thebfd.
    virtual ~Binary();
    // pure virtual  overrides ----------------
    void loadFill(uint1 *ptr,int4 size,const Address &addr) override;
    string getArchType(void) const override;
    void adjustVma(long adjust) override;
    // ----------------------------------------
    void open(void);		// Open any descriptors
    void close(void);		// Close any descriptor
    void attachToSpace(AddrSpace *id) { spaceid = id; }



};


}


#endif /* BINARYLOADER_H */
