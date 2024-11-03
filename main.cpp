#include "MediaFile.h"
//
// Created by Bogdan on 11/4/2024.
//
int main() {
    // Create an original MediaFile object
    MediaFile original("1984", "George Orwell", 1984);

    // Use the copy constructor to create a new MediaFile object
    MediaFile copy = original; // This calls the copy constructor
    return 0;
}