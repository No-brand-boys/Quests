cmake_minimum_required(VERSION 3.12)
project(cinema)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(cinema main.cpp client.h admin.h)
