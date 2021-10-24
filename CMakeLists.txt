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


add_executable(slgh-compile "") # sources will be added in add_subdirectory(..)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_dependencies(slgh-compile pcodeparse xml)
target_include_directories(
  slgh-compile
  PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)
