cmake_minimum_required(VERSION 3.16)

project(MDReaderWriter VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")    

add_library(${PROJECT_NAME} SHARED 
                inicpp/inicpp.hpp
                main.h
                main.cpp
)

target_include_directories(MDReaderWriter PUBLIC 
          ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/include
)
target_link_libraries(MDReaderWriter
          ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/lib/jsoncpp_static.lib
)