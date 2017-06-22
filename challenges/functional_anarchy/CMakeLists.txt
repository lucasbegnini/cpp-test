cmake_minimum_required(VERSION 3.5)
project("functionalAnarchy")

add_executable(functional_anarchy functional_anarchy.cpp)

enable_testing()

add_test(functionalTestInput1 functional_anarchy tests/input1.txt)
add_test(functionalTestInput2 functional_anarchy tests/input2.txt)
add_test(functionalTestInput3 functional_anarchy tests/input3.txt)
