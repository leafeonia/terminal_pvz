cmake_minimum_required(VERSION 3.14)
project(pvz)

set(CMAKE_CXX_STANDARD 14)

add_executable(pvz main.cpp Painter.cpp Painter.h common.h objects.cpp objects.h)