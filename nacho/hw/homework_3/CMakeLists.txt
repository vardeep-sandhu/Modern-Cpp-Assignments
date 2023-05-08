cmake_minimum_required (VERSION 3.16)

project(WebBrowser VERSION 1.0 LANGUAGES CXX)

# Add sub directories
add_subdirectory(src)

add_subdirectory(fmt EXCLUDE_FROM_ALL)
