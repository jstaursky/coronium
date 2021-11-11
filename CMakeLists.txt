cmake_minimum_required(VERSION 3.13)

project(coronium CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
# generate pcodeparse.cc
add_custom_target(pcodeparse echo "Creating pcodeparse.cc" DEPENDS ${CMAKE_SOURCE_DIR}/src/pcodeparse.cc)
add_custom_command(
  OUTPUT ${CMAKE_SOURCE_DIR}/src/pcodeparse.cc
  COMMAND ${BISON_EXECUTABLE}
  ARGS -y ${CMAKE_SOURCE_DIR}/parse/pcodeparse.y -p pcode -o ${CMAKE_SOURCE_DIR}/src/pcodeparse.cc
)
# generate xml.cc
add_custom_target(xml echo "Creating xml.cc" DEPENDS ${CMAKE_SOURCE_DIR}/src/xml.cc)
add_custom_command(
  OUTPUT ${CMAKE_SOURCE_DIR}/src/xml.cc
  COMMAND ${BISON_EXECUTABLE}
  ARGS -y ${CMAKE_SOURCE_DIR}/parse/xml.y -p xml -o ${CMAKE_SOURCE_DIR}/src/xml.cc
)
# generate slghparse.cc
bison_target(
  slgh-parse ${CMAKE_SOURCE_DIR}/parse/slghparse.y ${CMAKE_SOURCE_DIR}/src/slghparse.cc
  DEFINES_FILE ${CMAKE_SOURCE_DIR}/src/slghparse.tab.hh
)
# generate slghscan.cc
flex_target(
  slgh-scan ${CMAKE_SOURCE_DIR}/parse/slghscan.l
  ${CMAKE_SOURCE_DIR}/src/slghscan.cc
)
add_flex_bison_dependency(slgh-scan slgh-parse)

add_executable(slgh-compile "") # sources will be added through add_subdirectory(..)
add_library(coronium SHARED "")

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_dependencies(slgh-compile pcodeparse xml)
include_directories(
  ${CMAKE_SOURCE_DIR}/include/coronium
)

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
  ${CMAKE_SOURCE_DIR}/include/coronium/address.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/context.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/emulate.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/error.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/filemanage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/float.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/globalcontext.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/loadimage.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/memstate.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/opbehavior.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/opcodes.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/partmap.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/pcodecompile.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/pcoderaw.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/semantics.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/sleighbase.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/sleigh.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghpatexpress.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghpattern.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/slghsymbol.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/space.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/translate.hh
  ${CMAKE_SOURCE_DIR}/include/coronium/types.h
  ${CMAKE_SOURCE_DIR}/include/coronium/xml.hh
  DESTINATION
  include/coronium
)


# BUILD CPU SPEC FILES
file(COPY ${CMAKE_SOURCE_DIR}/processors DESTINATION ${CMAKE_BINARY_DIR}/)

add_custom_target(cpus
    COMMAND slgh-compile -a processors
    COMMENT "testing add_custom_target 'bar'..."
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS slgh-compile
)
