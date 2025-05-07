cmake_minimum_required(VERSION 3.31)
project(C_Silvio C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Rosseti)

add_executable(C_Silvio
        Rosseti/sandbox.c
        Rosseti/TAB.c
        Rosseti/TAB.h)
