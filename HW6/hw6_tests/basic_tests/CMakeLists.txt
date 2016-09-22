include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicHW6Tests ../basic_tests/basic_check.cpp)

target_link_libraries(runBasicHW6Tests gtest gtest_main)
target_link_libraries(runBasicHW6Tests hw6_library)