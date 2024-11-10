#include "MediaFile.h"
#include <iostream>

// Constructor
MediaFile::MediaFile(const std::string& title, const std::string& author, uint16_t year)
    : title(new std::string(title)), author(new std::string(author)), publication_year(year) {
    std::cout << "MediaFile Constructor called" << std::endl;
//    display_info();
}

// Copy Constructor
MediaFile::MediaFile(const MediaFile& other)
    : title(new std::string(*other.title)), // Deep copy title
    author(new std::string(*other.author)), // Deep copy author
    publication_year(other.publication_year) {
    std::cout << "MediaFile Copy Constructor called" << std::endl;
}

// Move Constructor
MediaFile::MediaFile(const MediaFile&& other) noexcept
    : title(other.title),
    author(other.author),
    publication_year(other.publication_year) {
    std::cout << "MediaFile Move Constructor called" << std::endl;

    // Set other's pointers to nullptr to avoid double deletion
    other.title = nullptr;
    other.author = nullptr;
}

// Destructor
MediaFile::~MediaFile() {
    std::cout << "MediaFile Destructor called" << std::endl;
    delete title;   // Free memory allocated for title
    delete author;  // Free memory allocated for author
}

// Implementation of display_info method
void MediaFile::display_info() const {
    std::cout << "display_info function has benn called." << std::endl;
    std::cout << "Title: " << *title << std::endl;
    std::cout << "Author: " << *author << std::endl;
    std::cout << "Year: " << publication_year << std::endl;
}

const std::string * MediaFile::get_title() const {
    return title;
}

const std::string * MediaFile::get_author() const {
    return author;
}

const uint16_t MediaFile::get_year() const {
    return publication_year;
}