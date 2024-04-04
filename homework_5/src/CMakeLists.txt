add_library(mat_serialization serialize.cpp convert_dataset.cpp)
add_library(convert_dataset convert_dataset.cpp)
add_executable(main main.cpp)
target_link_libraries (main mat_serialization convert_dataset ${OpenCV_LIBS})
