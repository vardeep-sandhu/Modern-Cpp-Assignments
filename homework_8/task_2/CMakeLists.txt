cmake_minimum_required(VERSION 3.0)
project(image)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(PNG REQUIRED)

# Include directories
include_directories(
    include
    io_tools
)

# Add your source file here
set(SOURCES
    src/homework_8.cpp
    io_tools/io_tools.cpp
)

# Set the output directory for binaries
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})
# add_library(${PROJECT_NAME} ${SOURCES})

# add_subdirectory(tests)