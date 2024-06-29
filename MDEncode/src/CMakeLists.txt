cmake_minimum_required(VERSION 3.16)

project(MDEncode VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME} SHARED MDEncode.cpp MDEncode.h)