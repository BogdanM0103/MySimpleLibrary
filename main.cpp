#include "MediaFile.h"
//
// Created by Bogdan on 11/4/2024.
//
#include "Book.h"
#include "Movie.h"
#include "UserInterface.h"

int main() {
    Movie m = Movie("Star Wars episode IV", "George Lucas", 1977, 120, "Long ago, in a galaxy far, far away..");
    m.display_info();
    return 0;
}
