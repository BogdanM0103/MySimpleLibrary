cmake_minimum_required(VERSION 3.24)
project(MySimpleLibrary)

set(CMAKE_CXX_STANDARD 20)

# Add include directory
include_directories(include)

# Add executables with updated path
add_executable(MySimpleLibrary
        src/MediaFile.cpp
        src/main.cpp
        src/Book.cpp
        src/Movie.cpp
        src/UserInterface.cpp
        src/Song.cpp
)
