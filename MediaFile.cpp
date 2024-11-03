#include "MediaFile.h"
#include <iostream>

// Constructor
MediaFile::MediaFile(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {  // Direct member initialization
    std::cout << "MediaFile constructor called" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Year: " << year << std::endl;
}

// Copy constructor
MediaFile::MediaFile(const MediaFile& other)
    : title(other.title), author(other.author), year(other.year) { // Direct member initialization
    std::cout << "MediaFile copy constructor called" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Year: " << year << std::endl;
}

// Destructor
MediaFile::~MediaFile() {
    std::cout << "MediaFile destructor called" << std::endl;
}
