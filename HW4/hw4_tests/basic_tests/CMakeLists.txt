include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicHW4Tests ../basic_tests/basic_check.cpp)

target_link_libraries(runBasicHW4Tests gtest gtest_main)
target_link_libraries(runBasicHW4Tests hw4_library)