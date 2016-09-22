include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMainHW6Tests ../main_tests/main_check.cpp)
target_link_libraries(runMainHW6Tests hw6_library gtest gtest_main)
