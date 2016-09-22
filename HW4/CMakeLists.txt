cmake_minimum_required(VERSION 2.8)

project(hw4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(hw4_run ${SOURCE_FILES})


include_directories(src)

add_subdirectory(src)
add_subdirectory(hw4_tests)


target_link_libraries(hw4_run hw4_library)