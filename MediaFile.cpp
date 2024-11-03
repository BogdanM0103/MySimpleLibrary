//
// Created by Bogdan on 11/4/2024.
//

#include "MediaFile.h"

#include <iostream>
#include <ostream>

MediaFile::MediaFile(const std::string& title, const std::string& author, const int year) : year(year) {
    this->title = new std::string(title);
    this->author = new std::string(author);
    std::cout << "MediaFile constructor called" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Year: " << year << std::endl;
}

MediaFile::~MediaFile() {
    std::cout << "MediaFile destructor called" << std::endl;
    delete this->title;
    delete this->author;
}

