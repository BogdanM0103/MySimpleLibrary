//
// Created by Bogdan on 11/6/2024.
//

#include "Song.h"

#include <iostream>
#include <ostream>

#include "MediaFile.h"

// Constructor
Song::Song(const std::string& title, const std::string& author, const uint16_t publication_year, const uint32_t duration_in_minutes, const std::string& format)
    : MediaFile(title, author, publication_year), duration_in_minutes(duration_in_minutes), format(new std::string(format)) {
    std::cout << "Song Constructor called." << std::endl;
}

// Destructor
Song::~Song() {
    delete format;
    std::cout << "Song Destructor called." << std::endl;
}

// Copy Constructor
Song::Song(const Song& other) : MediaFile(other), duration_in_minutes(other.duration_in_minutes), format(new std::string(*other.format)) {
    std::cout << "Song copy constructor called." << std::endl;
}

// Move Constructor
Song::Song(const Song&& other)
    : MediaFile(other), duration_in_minutes(other.duration_in_minutes), format(other.format) {
    std::cout << "Song Move Constructor called." << std::endl;
}

void Song::display_info() const {
    MediaFile::display_info();
    std::cout << "duration_in_minutes: " << duration_in_minutes << std::endl;
    std::cout << "Format: " << format << std::endl;
}
