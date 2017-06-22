cmake_minimum_required(VERSION 3.5)
project("stairwayToHeaven")

add_executable(stairway_to_heaven stairway_to_heaven.cpp)

enable_testing()

add_test(stairwayTestInput1 stairway_to_heaven tests/input1.txt)
add_test(stairwayTestInput2 stairway_to_heaven tests/input2.txt)
add_test(stairwayTestInput3 stairway_to_heaven tests/input3.txt)
add_test(stairwayTestInput4 stairway_to_heaven tests/input4.txt)
add_test(stairwayTestInput5 stairway_to_heaven tests/input5.txt)
add_test(stairwayTestInput6 stairway_to_heaven tests/input6.txt)

