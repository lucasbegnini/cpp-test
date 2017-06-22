cmake_minimum_required(VERSION 3.5)
project("Palindrome")

add_executable(palindrome palindrome.cpp)
add_test(palidromeTestInput1 palidrome tests/input1.txt)
add_test(palidromeTestInput2 palidrome tests/input2.txt)
