# Copyright (c) 2025 Ethan Sifferman.
# All rights reserved. Distribution Prohibited.

cmake_minimum_required(VERSION 3.10)

project(Performance VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(function_timer examples/function_timer.cpp)
add_executable(peach_snail examples/peach_snail.cpp)

add_executable(peach_snail_pg examples/peach_snail.cpp)
target_compile_options(peach_snail_pg PRIVATE -pg)
target_link_options(peach_snail_pg PRIVATE -pg)

add_custom_command(
    OUTPUT gmon.out
    COMMAND peach_snail_pg
    DEPENDS peach_snail_pg
    COMMENT "Running peach_snail_pg to generate gmon.out"
)

add_custom_target(gprof.svg
    COMMAND gprof peach_snail_pg gmon.out |
     gprof2dot -f prof -s -w
      --node-label=total-time-percentage --node-label=total-time |
     dot -Tsvg -o gprof.svg
    DEPENDS peach_snail_pg gmon.out
    COMMENT "Generating gprof.svg"
)
