cmake_minimum_required(VERSION 3.13)
project(Course)

set(CMAKE_CXX_STANDARD 17)

add_executable(Course main.cpp Models/Individual.h FileManager/FileManager.h UserInterface/Menu.h Models/Organization.h)