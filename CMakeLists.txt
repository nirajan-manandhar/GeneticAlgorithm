cmake_minimum_required(VERSION 3.12)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Tour.cpp Tour.hpp Population.cpp Population.hpp)