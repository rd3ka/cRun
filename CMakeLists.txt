cmake_minimum_required(VERSION 3.8)
project(cRun
        VERSION 1.0.0
        DESCRIPTION "gcc/g++ compilation abstraction layer for noobs"
      )
# Specify your desired compiler flags for clangd here
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

# Adjust the source file pattern if needed
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

