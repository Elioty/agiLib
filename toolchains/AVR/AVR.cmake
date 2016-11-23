cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0011 NEW)

include("${CMAKE_CURRENT_LIST_DIR}/../embedded.cmake")

set(CMAKE_ASM_COMPILER avr-gcc)
set(CMAKE_C_COMPILER   avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_AR           avr-ar)
set(CMAKE_RANLIB       avr-ranlib)

set(AVR_FLAGS "-D__AGILIB_PLATFORM_AVR -mcall-prologues")
set(__AGILIB_PLATFORM     "AVR")
set(__AGILIB_PLATFORM_AVR "TRUE")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${AVR_FLAGS}")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   ${AVR_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${AVR_FLAGS}")

unset(AVR_FLAGS)
