cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0011 NEW)

set(CMAKE_SYSTEM_NAME Generic)

include("${CMAKE_CURRENT_LIST_DIR}/common.cmake")

set(EMBEDDED_FLAGS "-D__AGILIB_EMBEDDED -Os -nostdinc")
set(__AGILIB_EMBEDDED "TRUE")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${EMBEDDED_FLAGS}")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   ${EMBEDDED_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EMBEDDED_FLAGS} \
                     -fno-rtti -fno-exceptions \
                     -nostdinc++")

unset(EMBEDDED_FLAGS)
