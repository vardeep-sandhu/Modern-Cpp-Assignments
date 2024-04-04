add_executable(main main.cpp )
target_link_libraries (main kmeans serialization bow_dictionary ${OpenCV_LIBS})