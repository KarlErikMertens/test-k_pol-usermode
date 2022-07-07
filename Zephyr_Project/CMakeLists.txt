# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.1.3)

set(CMAKE_VERBOSE_MAKEFILE ON)

list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../SecoSystem)
list(APPEND DTS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../SecoSystem)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(Zephyr_Project)

target_sources(app PRIVATE src/main.c)                             

zephyr_include_directories($ENV{ZEPHYR_BASE}/kernel/include)
zephyr_include_directories($ENV{ZEPHYR_BASE}/arch/x86/include/intel64)

set(CMAKE_C_FLAGS -Wno-unused-variable)
