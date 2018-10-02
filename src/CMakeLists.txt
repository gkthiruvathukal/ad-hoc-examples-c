cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(word_main word_main.cc word_entry.cc)

add_executable(word_entry_tests word_entry_tests.cc word_entry.cc)
target_link_libraries(word_entry_tests ${GTEST_LIBRARIES} pthread)
