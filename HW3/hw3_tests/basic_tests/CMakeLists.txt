include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicHW3Tests ../basic_tests/basic_check.cpp)

target_link_libraries(runBasicHW3Tests gtest gtest_main)
target_link_libraries(runBasicHW3Tests hw3_library)