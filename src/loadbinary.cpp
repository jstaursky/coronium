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

/* ================================================================================
 *
 * BinaryRaw
 *
 */
BinaryRaw::BinaryRaw (uint1* buffer, int4 sz) : LoadImage ("nofile")

{
    vma = 0;
    binaryBuffer = buffer;
    binsize = sz;
}

BinaryRaw::~BinaryRaw ()

{

}

// PUBLIC METHODS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
auto
BinaryRaw::setBaseAddress(uintb baseaddr) -> void

{
    adjustVma(baseaddr);
}

// --------------------------------------------------------------------------------
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
Range BinaryRaw::getAddressRange (uintb faddr, uintb laddr)

{
    return Range (this->spaceid, faddr, laddr);
}

/* ================================================================================
 *
 * Binary
 *
 */
int4 Binary::bfdinit = 0;	// Global initialization variable

Binary::Binary (const string& f, const string& t) : LoadImage (f)

{
  target = t;

  if (bfdinit == 0) {
    bfdinit = 1;
    bfd_init();
  }
  thebfd = (bfd *)0;
  spaceid = (AddrSpace *)0;

  bufsize = 512;		// Default buffer size
  bufoffset = ~((uintb)0);
  buffer = new uint1[ bufsize ];

  this->open();
}

Binary::~Binary ()

{
    if (thebfd != (bfd *) 0)
        close();
    delete [] buffer;
}

// PUBLIC METHODS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
auto
Binary::loadFill(uint1 *ptr,int4 size,const Address &addr) -> void

{
    asection* p;
    uintb secsize;
    uintb curaddr, offset;
    bfd_size_type readsize;
    int4 cursize;

    if (addr.getSpace() != spaceid)
        throw DataUnavailError ("Trying to get loadimage bytes from space: " + addr.getSpace()->getName());
    curaddr = addr.getOffset();
    if ((curaddr >= bufoffset) && (curaddr + size < bufoffset + bufsize))  	// Requested bytes were previously buffered
    {
        uint1* bufptr = buffer + (curaddr - bufoffset);
        memcpy (ptr, bufptr, size);
        return;
    }
    bufoffset = curaddr;		// Load buffer with bytes from new address
    offset = 0;
    cursize = bufsize;          // Read an entire buffer


    while (cursize > 0)
    {
        p = findSection (curaddr, secsize);
        if (p == (asection*)0) {
            if (offset == 0)    // Initial address not mapped
                break;
            memset (buffer + offset, 0, cursize); // Fill out the rest of the buffer with 0
            memcpy (ptr, buffer, size);
            return;
        }
        if (p->vma > curaddr) {	// No section matches
            if (offset == 0)    // Initial address not mapped
                break;
            readsize = p->vma - curaddr;
            if (readsize > cursize)
                readsize = cursize;
            memset (buffer + offset, 0, readsize); // Fill in with zeroes to next section
        } else {
            readsize = cursize;
            if (curaddr + readsize > p->vma + secsize) // Adjust to biggest possible read
                readsize = (bfd_size_type) (p->vma + secsize - curaddr);
            bfd_get_section_contents (thebfd, p, buffer + offset, (file_ptr) (curaddr - p->vma), readsize);
        }
        offset += readsize;
        cursize -= readsize;
        curaddr += readsize;
    }
    if (cursize > 0)
    {
        ostringstream errmsg;
        errmsg << "Unable to load " << dec << cursize << " bytes at " << addr.getShortcut();
        addr.printRaw (errmsg);
        throw DataUnavailError (errmsg.str());
    }
    memcpy (ptr, buffer, size);	// Copy requested bytes from the buffer
}

// --------------------------------------------------------------------------------
auto
Binary::open(void) -> void

{
    if (thebfd != (bfd*)0) throw LowlevelError ("BFD library did not initialize");
    thebfd = bfd_openr (filename.c_str(), target.c_str());
    if (thebfd == (bfd*)0)
    {
        std::string errmsg = "Unable to open binary file: ";
        errmsg += filename;
        throw LowlevelError (errmsg);
    }
    if (!bfd_check_format ( thebfd, bfd_object))
    {
        std::string errmsg = "File: ";
        errmsg += filename;
        errmsg += " : not in recognized object file format";
        throw LowlevelError (errmsg);
    }
    // Determine binary format (COFF, PE, ELF, ..., etc.).
    if (bfd_get_flavour (thebfd) == bfd_target_unknown_flavour)
    {
        std::string errmsg = "unrecognized binary format";
        throw LowlevelError (errmsg);
    }
}

// --------------------------------------------------------------------------------
auto
Binary::close(void) -> void

{
    bfd_close (thebfd);
    thebfd = (bfd*)0;
}

// --------------------------------------------------------------------------------
auto
Binary::getArchType(void) const -> std::string

{
    std::string type;
    std::string targ;
    type = bfd_printable_name (thebfd);
    type += ':';
    targ = thebfd->xvec->name;
    type += targ;
    return type;
}

// --------------------------------------------------------------------------------
auto
Binary::adjustVma(long adjust) -> void

{
    asection* s;
    adjust = AddrSpace::addressToByte (adjust, spaceid->getWordSize());
    for (s = thebfd->sections; s != (asection*)NULL; s = s->next)
    {
        s->vma += adjust;
        s->lma += adjust;
    }
}

// --------------------------------------------------------------------------------
auto
Binary::getAddressRange (uintb faddr, uintb laddr) -> Range

{
    return Range (this->spaceid, faddr, laddr);
}

// --------------------------------------------------------------------------------
auto
Binary::findSection(uintb offset,uintb &secsize) const -> asection *

{
    // Return section containing offset...
    asection* p;
    uintb start, stop;

    for (p = thebfd->sections; p != (asection*)NULL; p = p->next)
    {
        start = p->vma;
        secsize = (p->size != 0) ? p->size : p->rawsize;
        stop = start + secsize;
        if ((offset >= start) && (offset < stop))
            return p;
    }
    // ... or closest greater section.
    asection* result = (asection*)0;
    for (p = thebfd->sections; p != (asection*)NULL; p = p->next)
    {
        if (p->vma > offset) {
            if (result == (asection*)0)
                result = p;
            else if (p->vma < result->vma)
                result = p;
        }
    }
    return result;
}
