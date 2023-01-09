# CMakeList.txt : CMake project for Train_Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Train_Project "Train_Project.cpp" "Train_Project.h" "SkipList/SkipList.hpp" "SkipList/SkipList_test.hpp" "doctest.hpp" "RouteManager/RouteManager.cpp"  "Box/Box.hpp" "Box/BoxManagement.hpp" "Box/Box.cpp" "Box/BoxManagement.cpp"  "WalkManager/WalkManager.cpp")

# TODO: Add tests and install targets if needed.
