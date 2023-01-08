# CMakeList.txt : CMake project for Train_Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Train_Project "Train_Project.cpp" "Train_Project.h" "SkipList/SkipList.hpp" "SkipList/SkipList_test.hpp" "doctest.hpp" "Logic.hpp" "Logic.cpp" "Logic_test.hpp")

# TODO: Add tests and install targets if needed.
