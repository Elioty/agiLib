cmake_minimum_required(VERSION 3.0)

set(COMMON_FLAGS "-flto -Wall -Wextra -Werror -D__AGILIB")
set(__AGILIB "TRUE")

set(CMAKE_ASM_FLAGS "           ${COMMON_FLAGS}")
set(CMAKE_C_FLAGS   "-std=c11   ${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++11 ${COMMON_FLAGS}")

unset(COMMON_FLAGS)
