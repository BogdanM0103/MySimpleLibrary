#include "MediaFile.h"
//
// Created by Bogdan on 11/4/2024.
//
#include "Book.h"

int main() {
    Book myBook("1984", "George Orwell", 1949, 328, "A dystopian novel about totalitarianism.");
    myBook.display_info(); // Call the display_info method

    Book anotherBook = myBook; // Calls the copy constructor
    anotherBook.display_info();

    Book movedBook = std::move(myBook); // Calls the move constructor
    movedBook.display_info();

    return 0;
}
