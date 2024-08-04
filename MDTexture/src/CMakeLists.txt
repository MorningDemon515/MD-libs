cmake_minimum_required(VERSION 3.16)

project(MDTexture VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME} SHARED main.cpp main.h)

target_link_libraries(${PROJECT_NAME} dxgi dxguid)