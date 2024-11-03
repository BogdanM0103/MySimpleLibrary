#include "MediaFile.h"
#include <iostream>

// Constructor
MediaFile::MediaFile(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {  // Direct member initialization
    std::cout << "MediaFile constructor called" << std::endl;
}

// Copy constructor
MediaFile::MediaFile(const MediaFile& other)
    : title(other.title), author(other.author), year(other.year) { // Direct member initialization
    std::cout << "MediaFile copy constructor called" << std::endl;
}

// Move constructor
MediaFile::MediaFile(MediaFile&& other) noexcept
    : title(std::move(other.title)),  // Move title
      author(std::move(other.author)), // Move author
      year(other.year) {               // Copy year (no need to move)
    std::cout << "MediaFile move constructor called" << std::endl;

    // Optionally, reset the moved-from object
    other.year = 0; // Resetting year to a default value
}


// Destructor
MediaFile::~MediaFile() {
    std::cout << "MediaFile destructor called" << std::endl;
}

void MediaFile::display_info() const {
    std::cout << "display_info() called" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Year: " << year << std::endl;
}
