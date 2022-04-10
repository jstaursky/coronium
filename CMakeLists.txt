cmake_minimum_required(VERSION 3.13)

set(VERSION_MAJOR 0)            # PROJECT_VERSION_MAJOR
set(VERSION_MINOR 7)            # PROJECT_VERSION_MINOR
set(VERSION_PATCH 0)            # PROJECT_VERSION_PATCH

# Define the PROJECT_VERSION_... variables for use here-on.
project(coronium VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

# Shared library by default. Override with 'cmake -DBUILD_SHARED_LIBS=OFF ..'
option(BUILD_SHARED_LIBS "Build shared library" ON)

#                ### COMMAND-LINE OPTIONS FOR CMAKE BUILD ###
#
#  How to override sla files installation directory:
#
#    cmake .. -DSLA_LOCATION=<your-directory>
#
set(
  SLA_LOCATION "/var/coronium"
  CACHE STRING "Where to install .sla files."
)

# Create the convenience header "coronium.hpp" which defines the macro SLA_LOCATION(cpu)
configure_file(
  ${CMAKE_SOURCE_DIR}/include/coronium/coronium.hpp.in
  ${CMAKE_BINARY_DIR}/coronium.hpp
)
install(FILES "${CMAKE_BINARY_DIR}/coronium.hpp" DESTINATION include/coronium)
install(FILES "${CMAKE_SOURCE_DIR}/include/coronium/loadbinary.hpp" DESTINATION include/coronium)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Ghidra code handling
set(DEPS_GHIDRA "${CMAKE_SOURCE_DIR}/dependencies/ghidra")

# Generate pcodeparse.cc
add_custom_target(
  pcodeparse
  echo "Creating pcodeparse.cc"
  DEPENDS ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
)
add_custom_command(
  OUTPUT ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
  COMMAND ${BISON_EXECUTABLE}
  ARGS -y ${DEPS_GHIDRA}/parse/pcodeparse.y -p pcode -o ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
)
# Generate xml.cc
add_custom_target(
  xml
  echo "Creating xml.cc"
  DEPENDS ${CMAKE_BINARY_DIR}/src/xml.cc
)
add_custom_command(
  OUTPUT ${CMAKE_BINARY_DIR}/src/xml.cc
  COMMAND ${BISON_EXECUTABLE}
  ARGS -y ${DEPS_GHIDRA}/parse/xml.y -p xml -o ${CMAKE_BINARY_DIR}/src/xml.cc
)
# Generate slghparse.cc
bison_target(
  slgh-parse ${DEPS_GHIDRA}/parse/slghparse.y ${CMAKE_BINARY_DIR}/src/slghparse.cc
  DEFINES_FILE ${CMAKE_BINARY_DIR}/src/slghparse.tab.hh
)
# Generate slghscan.cc
flex_target(
  slgh-scan ${DEPS_GHIDRA}/parse/slghscan.l
  ${CMAKE_BINARY_DIR}/src/slghscan.cc
)
add_flex_bison_dependency(slgh-scan slgh-parse)

#                          ### PRIMARY TARGETS ###
#
# NOTE: sources are added through add_subdirectory(..)
#
add_executable(slgh-compile "")

add_library(coronium "")

find_library(BFD bfd)
if(BFD)
  message(STATUS "Found libbfd\n")
  target_link_libraries(coronium ${BFD})
  install(
    FILES
    ${DEPS_GHIDRA}/include/bfd_arch.hh
    ${DEPS_GHIDRA}/include/loadimage_bfd.hh
    DESTINATION
    include/coronium
  )
else()
  message(FATAL_ERROR "unable to find requirement: libbfd .\n")
endif()

if(NOT CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR lib)
endif()

# Adding versioning and symbolic links to libcoronium.so
# (adds '-Wl,-soname,libcoronium.so.<major_version>' compiler flag.)
set_target_properties(
  coronium PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

add_subdirectory(${DEPS_GHIDRA}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_dependencies(slgh-compile pcodeparse xml)

# SLEIGH COMPILER
install(
  TARGETS
  slgh-compile
  DESTINATION
  bin
)

# libcoronium.so
install(
  TARGETS
  coronium
  DESTINATION
  lib
)

# CORONIUM HEADER FILES
install(
  FILES
  ${DEPS_GHIDRA}/include/action.hh
  ${DEPS_GHIDRA}/include/address.hh
  ${DEPS_GHIDRA}/include/architecture.hh
  ${DEPS_GHIDRA}/include/blockaction.hh
  ${DEPS_GHIDRA}/include/block.hh
  ${DEPS_GHIDRA}/include/capability.hh
  ${DEPS_GHIDRA}/include/cast.hh
  ${DEPS_GHIDRA}/include/comment.hh
  ${DEPS_GHIDRA}/include/condexe.hh
  ${DEPS_GHIDRA}/include/context.hh
  ${DEPS_GHIDRA}/include/coreaction.hh
  ${DEPS_GHIDRA}/include/cover.hh
  ${DEPS_GHIDRA}/include/cpool.hh
  ${DEPS_GHIDRA}/include/crc32.hh
  ${DEPS_GHIDRA}/include/database.hh
  ${DEPS_GHIDRA}/include/double.hh
  ${DEPS_GHIDRA}/include/dynamic.hh
  ${DEPS_GHIDRA}/include/emulate.hh
  ${DEPS_GHIDRA}/include/emulateutil.hh
  ${DEPS_GHIDRA}/include/error.hh
  ${DEPS_GHIDRA}/include/filemanage.hh
  ${DEPS_GHIDRA}/include/float.hh
  ${DEPS_GHIDRA}/include/flow.hh
  ${DEPS_GHIDRA}/include/fspec.hh
  ${DEPS_GHIDRA}/include/funcdata.hh
  ${DEPS_GHIDRA}/include/globalcontext.hh
  ${DEPS_GHIDRA}/include/heritage.hh
  ${DEPS_GHIDRA}/include/inject_sleigh.hh
  ${DEPS_GHIDRA}/include/jumptable.hh
  ${DEPS_GHIDRA}/include/loadimage.hh
  ${DEPS_GHIDRA}/include/memstate.hh
  ${DEPS_GHIDRA}/include/merge.hh
  ${DEPS_GHIDRA}/include/opbehavior.hh
  ${DEPS_GHIDRA}/include/opcodes.hh
  ${DEPS_GHIDRA}/include/op.hh
  ${DEPS_GHIDRA}/include/options.hh
  ${DEPS_GHIDRA}/include/override.hh
  ${DEPS_GHIDRA}/include/partmap.hh
  ${DEPS_GHIDRA}/include/pcodecompile.hh
  ${DEPS_GHIDRA}/include/pcodeinject.hh
  ${DEPS_GHIDRA}/include/pcodeparse.hh
  ${DEPS_GHIDRA}/include/pcoderaw.hh
  ${DEPS_GHIDRA}/include/prefersplit.hh
  ${DEPS_GHIDRA}/include/prettyprint.hh
  ${DEPS_GHIDRA}/include/printc.hh
  ${DEPS_GHIDRA}/include/printlanguage.hh
  ${DEPS_GHIDRA}/include/rangemap.hh
  ${DEPS_GHIDRA}/include/rangeutil.hh
  ${DEPS_GHIDRA}/include/ruleaction.hh
  ${DEPS_GHIDRA}/include/semantics.hh
  ${DEPS_GHIDRA}/include/sleigh_arch.hh
  ${DEPS_GHIDRA}/include/sleighbase.hh
  ${DEPS_GHIDRA}/include/sleigh.hh
  ${DEPS_GHIDRA}/include/slghparse.hh
  ${DEPS_GHIDRA}/include/slghpatexpress.hh
  ${DEPS_GHIDRA}/include/slghpattern.hh
  ${DEPS_GHIDRA}/include/slghsymbol.hh
  ${DEPS_GHIDRA}/include/space.hh
  ${DEPS_GHIDRA}/include/stringmanage.hh
  ${DEPS_GHIDRA}/include/subflow.hh
  ${DEPS_GHIDRA}/include/transform.hh
  ${DEPS_GHIDRA}/include/translate.hh
  ${DEPS_GHIDRA}/include/type.hh
  ${DEPS_GHIDRA}/include/typeop.hh
  ${DEPS_GHIDRA}/include/types.h
  ${DEPS_GHIDRA}/include/userop.hh
  ${DEPS_GHIDRA}/include/variable.hh
  ${DEPS_GHIDRA}/include/varmap.hh
  ${DEPS_GHIDRA}/include/varnode.hh
  ${DEPS_GHIDRA}/include/xml.hh
  DESTINATION
  include/coronium
)

# BUILD CPU SPEC FILES
file(COPY ${DEPS_GHIDRA}/processors DESTINATION ${CMAKE_BINARY_DIR}/)
add_custom_target(
  cpus
  COMMAND slgh-compile -a processors
  COMMENT "BUILDING .sla CPU SPECIFICATION FILES"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  DEPENDS slgh-compile
)
add_custom_command(
  TARGET cpus POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_BINARY_DIR}/processors
  ${SLA_LOCATION}
  COMMENT "CPU specification folders are installed in ${SLA_LOCATION}"
)

# Support for pkg-config
configure_file(coronium.pc.in ${CMAKE_BINARY_DIR}/coronium.pc @ONLY)

install(
  FILES
  "${CMAKE_BINARY_DIR}/coronium.pc"
  DESTINATION
  "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

message(
  STATUS
  "SUMMARY\n"
  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% INFO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
  "   .sla files will be installed in: " "${SLA_LOCATION}" "\n"
  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% HOW TO UNINSTALL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
  "   uninstall everything via \"xargs rm < install_manifest.txt\"\n"
  "   (However, you must remove the folder ${CMAKE_INSTALL_PREFIX}/include/coronium, manually)" "\n"
  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
)
