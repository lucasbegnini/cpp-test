cmake_minimum_required(VERSION 3.5)
project("csv")

enable_testing()
add_executable(csv csv.cpp)

add_test(csvTestInput1 csv tests/input1.txt)
