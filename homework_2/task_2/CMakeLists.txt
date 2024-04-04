cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #make json with all compile commands. Better understanding?

project(
  InputParser
  VERSION 1.0
  LANGUAGES CXX)

if (UNIX)
  set (CMAKE_CXX_FLAGS "-g3 -Wall -O0")
endif ()

set(PROJLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include CACHE INTERNAL "")
set(PROJLIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src CACHE INTERNAL "")

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/results/)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(task_2 src/main.cpp)
