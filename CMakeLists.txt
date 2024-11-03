cmake_minimum_required(VERSION 3.29)
project(MySimpleLibrary)

set(CMAKE_CXX_STANDARD 20)

add_executable(MySimpleLibrary
        MediaFile.cpp
        MediaFile.h
        main.cpp
)
