cmake_minimum_required(VERSION 3.6)
project(acd21_PA4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CashReg.h cashRegImp.cpp)
add_executable(acd21_PA4 ${SOURCE_FILES})