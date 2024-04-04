cmake_minimum_required(VERSION 3.1)
project(opencv_test)

find_package(OpenCV 4 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  message(STATUS "OpenCV directories: ${OpenCV_INCLUDE_DIRS}")
  include_directories(${OpenCV_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(main main.cpp)
target_link_libraries(main  ${OpenCV_LIBS})
