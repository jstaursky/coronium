cmake_minimum_required(VERSION 3.13)

set(VERSION_MAJOR 0)            # PROJECT_VERSION_MAJOR
set(VERSION_MINOR 2)            # PROJECT_VERSION_MINOR
set(VERSION_PATCH 1)            # PROJECT_VERSION_PATCH

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
  SLA_LOCATION "/var/coronium/"
  CACHE STRING "Where to install .sla files."
)

# Create the convenience header "coronium.hpp" which defines the macro SLA_LOCATION(cpu)
configure_file(
  ${CMAKE_SOURCE_DIR}/include/coronium/config.hpp.in
  ${CMAKE_BINARY_DIR}/coronium.hpp
)
install(FILES "${CMAKE_BINARY_DIR}/coronium.hpp" DESTINATION include/coronium)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Generate pcodeparse.cc
add_custom_target(
  pcodeparse
  echo "Creating pcodeparse.cc"
  DEPENDS ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
)
add_custom_command(
  OUTPUT ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
  COMMAND ${BISON_EXECUTABLE}
  ARGS -y ${CMAKE_SOURCE_DIR}/parse/pcodeparse.y -p pcode -o ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
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
  ARGS -y ${CMAKE_SOURCE_DIR}/parse/xml.y -p xml -o ${CMAKE_BINARY_DIR}/src/xml.cc
)
# Generate slghparse.cc
bison_target(
  slgh-parse ${CMAKE_SOURCE_DIR}/parse/slghparse.y ${CMAKE_BINARY_DIR}/src/slghparse.cc
  DEFINES_FILE ${CMAKE_SOURCE_DIR}/src/slghparse.tab.hh
)
# Generate slghscan.cc
flex_target(
  slgh-scan ${CMAKE_SOURCE_DIR}/parse/slghscan.l
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
    ${CMAKE_SOURCE_DIR}/include/coronium/bfd_arch.hh
    ${CMAKE_SOURCE_DIR}/include/coronium/loadimage_bfd.hh
    DESTINATION
    include/coronium
  )
else()
  message(STATUS "WARNING: unable to find libbfd, bfd dependent content will be omitted from install.\n")
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

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_dependencies(slgh-compile pcodeparse xml)
include_directories(${CMAKE_SOURCE_DIR}/include/coronium)

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
  ${CMAKE_SOURCE_DIR}/include/coronium/action.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/address.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/architecture.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/blockaction.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/block.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/capability.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/cast.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/comment.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/condexe.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/context.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/coreaction.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/cover.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/cpool.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/crc32.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/database.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/double.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/dynamic.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/emulate.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/emulateutil.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/error.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/filemanage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/float.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/flow.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/fspec.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/funcdata.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/globalcontext.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/heritage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/inject_sleigh.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/jumptable.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/loadimage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/memstate.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/merge.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/opbehavior.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/opcodes.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/op.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/options.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/override.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/partmap.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/pcodecompile.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/pcodeinject.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/pcodeparse.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/pcoderaw.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/prefersplit.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/prettyprint.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/printc.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/printlanguage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/rangemap.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/rangeutil.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/ruleaction.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/semantics.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/sleigh_arch.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/sleighbase.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/sleigh.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghparse.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghpatexpress.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghpattern.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghsymbol.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/space.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/stringmanage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/subflow.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/transform.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/translate.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/type.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/typeop.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/types.h
  ${CMAKE_SOURCE_DIR}/include/coronium/userop.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/variable.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/varmap.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/varnode.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/xml.hh
  DESTINATION
  include/coronium
)

# BUILD CPU SPEC FILES
file(COPY ${CMAKE_SOURCE_DIR}/processors DESTINATION ${CMAKE_BINARY_DIR}/)
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
