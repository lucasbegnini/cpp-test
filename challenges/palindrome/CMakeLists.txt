cmake_minimum_required(VERSION 3.5)
project("palindrome")

add_executable(palindrome palindrome.cpp)

enable_testing()

add_test(palidromeTestInput1 palindrome tests/input1.txt)
add_test(palidromeTestInput2 palindrome tests/input2.txt)
