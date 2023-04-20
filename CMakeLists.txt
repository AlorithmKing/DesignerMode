cmake_minimum_required(VERSION 3.24)
project(DesignerMode)

set(CMAKE_CXX_STANDARD 17)

add_executable(DesignerMode AbstratFactory.cpp)

add_executable(ObseverMode ObseverMode.cpp)

add_executable(Adapter Adapter.cpp AVLTree.h)

add_executable(AVL AVLTest.cpp)