add_library(sift_compute_lib SHARED sift.cpp)
target_link_libraries(sift_compute_lib ${OpenCV_LIBS})