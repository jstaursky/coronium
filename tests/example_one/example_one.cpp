/* ###
 * IP: GHIDRA
 * NOTE: mentions GNU libbfd, the hard-coded binary is a toy function that generates primes
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// Dump the raw pcode instructions

// Root include for parsing using SLEIGH
#include <coronium/coronium.hpp>
#include <coronium/types.h>
#include <coronium/loadimage.hh>
#include <coronium/sleigh.hh>
#include <coronium/emulate.hh>

#include <iostream>

int main(int argc, char **argv)

{
  // For fun try playing other cpu interpretations of bytes. Try:
  // 8085:LE:16:default
  uint1 payload[] = {
      0x66, 0x68, 0xeb, 0x05, 0x31, 0xc0,
      0x74, 0xfa, 0xe8, 0xff, 0xc0, 0x67, 0x48
  };

  auto coro = coronium::Coronium ("x86:LE:32:default");

  std::cout << coro.getArchType () << std::endl;
  coro.load (0x00000000, payload, sizeof (payload));

  std::vector<coronium::Instruction> insn = coro.dump(0x00000000, sizeof(payload));

  for (auto i : insn) {
      std::cout << i.assembly.mnemonic << " "
                << i.assembly.body
                << std::endl;
  }

}
