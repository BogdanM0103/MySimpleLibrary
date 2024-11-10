//
// Created by User on 11/4/2024.
//

#include <iostream>
#include "Movie.h"

// Constructor
Movie::Movie(const std::string& title, const std::string& author, const uint16_t publication_date, const uint16_t length, const std::string& description)
    : MediaFile(title, author, publication_date), length(length), description(new std::string(description)) {
    std::cout << "Movie Constructor called" << std::endl;
}

// Copy Constructor
Movie::Movie(const Movie& other)
    : MediaFile(other), length(other.length), description(new std::string(*other.description)) {
    std::cout << "Movie Copy Constructor called" << std::endl;
}

// Move Constructor
Movie::Movie(Movie&& other) noexcept
    : MediaFile(other), length(other.length), description(other.description) {
    std::cout << "Movie Move Constructor called" << std::endl;
    other.length = 0;
    other.description = nullptr;
}

// Destructor
Movie::~Movie() {
    delete description;
    std::cout << "Movie destructor called" << std::endl;
}

const std::string* Movie::get_title() const {
    return MediaFile::get_title();
}

void Movie::display_info() const {
    MediaFile::display_info();
    std::cout << "Length in minutes:" << length << std::endl;
    std::cout << "Description:" << *description << std::endl;
}
