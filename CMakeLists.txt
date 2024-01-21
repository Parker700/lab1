#setting CMake version
cmake_minimum_required(VERSION 3.23)

#project name
project(lab1)

#Programming language standard
set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 main.cpp program1.h functions.cpp)
