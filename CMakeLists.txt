cmake_minimum_required(VERSION 3.0)
project(agiLib)

set(DELIV_DIR "${CMAKE_CURRENT_LIST_DIR}/deliv/${__AGILIB_CPU}")
set(HEADERS_DELIV_DIR "${DELIV_DIR}/include")
set(TOOLCHAINS_DELIV_DIR "${DELIV_DIR}/toolchains")

include(${CMAKE_CURRENT_LIST_DIR}/toolchains/install.cmake)

list(APPEND SOURCES)
include(${CMAKE_CURRENT_LIST_DIR}/sys/sys.cmake)

# It could be a headers-only lib
if(SOURCES)
endif()
