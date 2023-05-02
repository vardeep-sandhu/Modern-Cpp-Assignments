# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.16)

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #make json with all compile commands. Better understanding?
# Find packages go here.

# You should usually split this into folders, but this is a simple example

set(PROJLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include CACHE INTERNAL "")
set(PROJLIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")

# include_directories(PROJLIB_INCLUDE_DIR)

file(GLOB_RECURSE PROJLIB_HEADERS ${PROJLIB_INCLUDE_DIR}/*.hpp)
file(GLOB_RECURSE PROJLIB_SOURCES ${PROJLIB_SOURCE_DIR}/*.cpp)

list(REMOVE_ITEM PROJLIB_SOURCES ${PROJLIB_SOURCE_DIR}/main.cpp) #dont want the main.cpp to be included in lib.

message("This is how you print a message in cmake")
message("${PROJLIB_SOURCE_DIR}")
message("${PROJLIB_HEADERS}")
message("${PROJLIB_SOURCES}")
# message("${PROJLIB_SOURCE_DIR}")
# message("${PROJLIB_SOURCE_DIR}")
# message("${PROJLIB_SOURCE_DIR}")


# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
# add_library(ipb_arithmetic sum.cpp subtract.cpp ../include/ipb_arithmetic.hpp)

add_library(ipb_arithmetic ${PROJLIB_SOURCES})
target_include_directories(ipb_arithmetic PUBLIC ${PROJLIB_INCLUDE_DIR})

# target_include_directories(ProjLib PUBLIC ${PROJLIB_INCLUDE_DIR})

# # Make sure you link your targets with this command. It can also link libraries and
# # even flags, so linking a target that does not exist will not give a configure-time error.
# target_link_libraries(MyExample PRIVATE MyLibExample)

add_executable(main main.cpp)
target_link_libraries(main ipb_arithmetic)