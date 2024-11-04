//
// Created by User on 11/4/2024.
//

#include <iostream>
#include "Movie.h"

Movie::Movie(const std::string& title, const std::string& author, const int publication_date, const int length, const std::string& description)
    : MediaFile(title, author, publication_date), length(length), description(new std::string(description)) {
    std::cout << "Movie Constructor called" << std::endl;
}

Movie::Movie(const Movie& other)
    : MediaFile(other), length(other.length), description(new std::string(*other.description)) {
    std::cout << "Movie Copy Constructor called" << std::endl;
}

Movie::Movie(Movie&& other) noexcept
    : MediaFile(other), length(other.length), description(other.description) {
    std::cout << "Movie Move Constructor called" << std::endl;
    other.length = 0;
    other.description = nullptr;
}

Movie::~Movie() {
    delete description;
    std::cout << "Movie destructor called" << std::endl;
}

void Movie::display_info() const {
    MediaFile::display_info();
    std::cout << "Length in minutes:" << length << std::endl;
    std::cout << "Description:" << *description << std::endl;
}
