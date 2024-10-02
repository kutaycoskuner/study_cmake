# required: set required cmake version
cmake_minimum_required(VERSION 3.24)

# required: set the project name
project(tutorial)

# add the executable (executable called first param, using the second param as source)
add_executable(${PROJECT_NAME} main.cpp)