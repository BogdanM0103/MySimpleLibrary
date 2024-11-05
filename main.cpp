#include "MediaFile.h"
//
// Created by Bogdan on 11/4/2024.
//
#include "Book.h"
#include "Movie.h"
#include "UserInterface.h"

int main() {
    MediaFile f("1984", "George Orwell", 1984);
    f.display_info();
    return 0;
}
