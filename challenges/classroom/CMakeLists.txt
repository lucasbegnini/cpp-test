cmake_minimum_required(VERSION 3.5)
project("classroom")

add_executable(classroom classroom.cpp)

add_test(classroomTestInput1 classroom tests/input1.txt)
add_test(classroomTestInput2 classroom tests/input2.txt)
add_test(classroomTestInput3 classroom tests/input3.txt)
