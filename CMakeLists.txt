cmake_minimum_required(VERSION 3.5)
project(PolynomialArithmetic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Term.cpp Term.h Polynomial.cpp Polynomial.h)
add_executable(PolynomialArithmetic ${SOURCE_FILES})