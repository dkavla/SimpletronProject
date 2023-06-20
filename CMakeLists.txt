
cmake_minimum_required(VERSION 3.25)
project(Simpletron)

set(CMAKE_CXX_STANDARD 20)

add_executable(SMLComp 
                src/main.cpp
                src/operations.cpp
                src/operations.h
)