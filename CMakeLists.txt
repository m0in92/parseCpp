cmake_minimum_required(VERSION 3.23)
project(csv_data_parse_example)

set(CMAKE_CXX_STANDARD 14)

add_executable(csv_data_parse_example main.cpp dataframe.h dataframe.cpp)
