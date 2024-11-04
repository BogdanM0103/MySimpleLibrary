#include "MediaFile.h"
//
// Created by Bogdan on 11/4/2024.
//
#include "Book.h"
#include "Movie.h"
#include "UserInterface.h"

int main() {
    Book b = Book("1984", "George Orwell", 1945, 500, "A book about a dystopian society.");
    b.display_info();
    return 0;
}
