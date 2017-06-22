cmake_minimum_required(VERSION 3.5)
project("dirtyBill")

enable_testing()
add_executable(dirty_bills dirty_bills.cpp)

add_test(dirtyBillsTest1 dirty_bills tests/input1.txt)
add_test(dirtyBillsTest2 dirty_bills tests/input2.txt)
add_test(dirtyBillsTest3 dirty_bills tests/input3.txt)
