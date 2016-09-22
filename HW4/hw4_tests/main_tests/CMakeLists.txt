include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMainHW4Tests ../main_tests/main_check.cpp)
#set_target_properties (runMainHW3Tests PROPERTIES COMMAND_LINE_ARGUMENTS "--gtest_color=yes")

target_link_libraries(runMainHW4Tests gtest gtest_main)
target_link_libraries(runMainHW4Tests hw4_library)