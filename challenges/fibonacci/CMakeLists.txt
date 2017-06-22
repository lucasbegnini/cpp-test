cmake_minimum_required(VERSION 3.5)
project("anagram")

add_executable(fibonacci fibonacci.cpp)

enable_testing()

add_test(fibonacciTestInput1 fibonacci tests/input1.txt)
add_test(fibonacciTestInput2 fibonacci tests/input2.txt)
add_test(fibonacciTestInput3 fibonacci tests/input3.txt)
add_test(fibonacciTestInput4 fibonacci tests/input4.txt)
add_test(fibonacciTestInput5 fibonacci tests/input5.txt)
add_test(fibonacciTestInput6 fibonacci tests/input6.txt)
