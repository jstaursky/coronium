#
# Manage coronium source file separately.
#
add_library(
  coronium_impl
  OBJECT
  coronium.cpp
  loadbinary.cpp
)

if(BUILD_SHARED_LIBS)
  set_property(TARGET coronium_impl PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()

target_include_directories(
  coronium_impl
  PRIVATE
  ${CMAKE_BINARY_DIR}           # For coronium.hpp
  ${CMAKE_SOURCE_DIR}/include/coronium
  ${DEPS_GHIDRA}/include
)
target_link_libraries(coronium $<TARGET_OBJECTS:coronium_impl>)
