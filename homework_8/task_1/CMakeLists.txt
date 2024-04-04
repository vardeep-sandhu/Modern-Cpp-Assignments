cmake_minimum_required(VERSION 3.0)
project(stack_limit)

# Add your source file here
set(SOURCES
    stack_mem.cpp
)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})
