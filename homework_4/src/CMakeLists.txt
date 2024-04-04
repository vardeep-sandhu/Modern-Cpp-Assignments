add_library(ipb_algorithm named_vector.cpp ipb_algorithm.cpp)
add_executable(main main.cpp)
target_link_libraries (main ipb_algorithm)