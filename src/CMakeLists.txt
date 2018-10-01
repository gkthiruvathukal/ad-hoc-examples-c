cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(word_main word_main.cc word_entry.cc)

#add_executable(square_root_tests square_root_tests.cpp square_root.cpp)
#target_link_libraries(square_root_tests ${GTEST_LIBRARIES} pthread)
