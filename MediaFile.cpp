#include "MediaFile.h"
#include <iostream>

// Constructor
MediaFile::MediaFile(const std::string& title, const std::string& author, int year)
    : title(new std::string(title)), author(new std::string(author)), year(year) {
    std::cout << "MediaFile constructor called" << std::endl;
    display_info();
}

// Copy constructor
MediaFile::MediaFile(const MediaFile& other)
    : title(new std::string(*other.title)), author(new std::string(*other.author)), year(other.year) {
    std::cout << "MediaFile copy constructor called" << std::endl;
    display_info();
}

// Move constructor
MediaFile::MediaFile(MediaFile&& other) noexcept
    : title(other.title),
      author(other.author),
      year(other.year) {
    std::cout << "MediaFile move constructor called" << std::endl;
    display_info();

    // Reset the moved-from object
    other.title = nullptr;
    other.author = nullptr;
}

// Destructor
MediaFile::~MediaFile() {
    std::cout << "MediaFile destructor called" << std::endl;
    delete title;   // Free memory allocated for title
    delete author;  // Free memory allocated for author
}

// Implementation of display_info method
void MediaFile::display_info() const {
    std::cout << "Title: " << *title << std::endl;
    std::cout << "Author: " << *author << std::endl;
    std::cout << "Year: " << year << std::endl;
}
