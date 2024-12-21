cmake_minimum_required(VERSION 3.26)
project(BankAccount_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankAccount_cpp main.cpp classes.h functions.h functions.cpp
        classes.cpp)
