cmake_minimum_required(VERSION 3.10)
project (HW_5)

find_package(OpenCV 4 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  message(STATUS "OpenCV directories: ${OpenCV_INCLUDE_DIRS}")
  include_directories(${OpenCV_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
include_directories(include)
add_subdirectory(src)