//
// Created by Bogdan on 11/4/2024.
//

#include "Book.h"
#include <iostream>

// Constructor
Book::Book(const std::string& title, const std::string& author, int year, int pages, const std::string& description)
    : MediaFile(title, author, year), // Call the base class constructor
      pages(pages),
      description(new std::string(description)) { // Allocate memory for description
    std::cout << "Book constructor called" << std::endl;
    display_info();
}

// Copy constructor
Book::Book(const Book& other)
    : MediaFile(other), // Call the base class copy constructor
      pages(other.pages),
      description(new std::string(*other.description)) { // Deep copy for description
    std::cout << "Book copy constructor called" << std::endl;
    display_info();
}

// Move constructor
Book::Book(Book&& other) noexcept
    : MediaFile(std::move(other)), // Call the base class move constructor
      pages(other.pages),
      description(other.description) { // Transfer ownership of description

    std::cout << "Book move constructor called" << std::endl;
    display_info();

    // Reset the moved-from object
    other.pages = 0;           // Optionally reset pages
    other.description = nullptr; // Prevent double deletion
}

// Destructor
Book::~Book() {
    std::cout << "Book destructor called" << std::endl;
    delete description; // Free memory allocated for description
}

// Override display_info method
void Book::display_info() const {
    MediaFile::display_info(); // Call the base class display_info
    std::cout << "Pages: " << pages << std::endl;
    std::cout << "Description: " << (description ? *description : "No description") << std::endl;
}
