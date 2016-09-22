cmake_minimum_required(VERSION 2.8)
project(hw3)

#add_definitions(-std=c++11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")

set(SOURCE_FILES main.cpp)



#file(GLOB_RECURSE SOURCE_FILES "*.cpp")
#file(GLOB_RECURSE HEADER_FILES "*.h")

add_executable(hw3_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(hw3_tests)

target_link_libraries(hw3_run hw3_library)
