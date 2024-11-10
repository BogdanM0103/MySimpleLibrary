//
// Created by Bogdan on 11/4/2024.
//

#ifndef BOOK_H
#define BOOK_H

#include "MediaFile.h"

class Book : public MediaFile {
public:
    // Constructor
    Book(const std::string& title, const std::string& author, uint16_t year, uint16_t pages, const std::string& description);

    // Copy constructor
    Book(const Book& other);

    // Move constructor
    Book(Book&& other) noexcept;

    // Destructor
    ~Book();

    // Override display_info method to include additional information
    void display_info() const override; // This will now correctly override

private:
    int pages;                // Number of pages in the book
    std::string* description; // Pointer for a short description of the book
};

#endif //BOOK_H
