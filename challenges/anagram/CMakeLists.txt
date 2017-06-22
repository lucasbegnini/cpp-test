cmake_minimum_required(VERSION 3.5)
project("anagram")

add_executable(anagram anagram.cpp)

enable_testing()

add_test(anagramTestInput1 anagram tests/input1.txt)
add_test(anagramTestInput2 anagram tests/input2.txt)
