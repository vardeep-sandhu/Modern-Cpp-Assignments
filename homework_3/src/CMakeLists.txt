cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #make json with all compile commands. Better understanding?

project(
  WebBrowser
  VERSION 1.0
  LANGUAGES CXX)

# if (UNIX)
set (CMAKE_CXX_FLAGS "-g3 -Wall -O3")
# endif ()

set(PROJLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/api CACHE INTERNAL "")
set(PROJLIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")

message(${PROJLIB_INCLUDE_DIR})
message(${PROJLIB_SOURCE_DIR})

add_library(html_writer ${PROJLIB_SOURCE_DIR}/html_writer.cpp ${PROJLIB_SOURCE_DIR}/image_browser.cpp)
target_include_directories(html_writer PUBLIC ${PROJLIB_INCLUDE_DIR})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/results/)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(fmt)

add_executable(main main.cpp)
target_link_libraries(main html_writer fmt::fmt)