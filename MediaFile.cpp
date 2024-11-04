#include "MediaFile.h"
#include <iostream>

// Constructor
MediaFile::MediaFile(const std::string& title, const std::string& author, uint16_t year)
    : title(new std::string(title)), author(new std::string(author)), year(year) {
    std::cout << "MediaFile constructor called" << std::endl;
//    display_info();
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
