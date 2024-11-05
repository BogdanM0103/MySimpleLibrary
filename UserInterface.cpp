//
// Created by User on 11/4/2024.
//

#include <iostream>
#include "UserInterface.h"

#include <cstdint>
#include <limits>

#include "Book.h"
#include "Movie.h"

UserInterface::UserInterface() : running(true) {
    std::cout << "UserInterface Constructor called" << std::endl;
}

void UserInterface::run() {
    int temp_option;
    while (running) {
        display_menu();
        std::cout << "Enter your option: ";
        std::cin >> temp_option;

        if (std::cin.fail() || temp_option < 1 || temp_option > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue;
        }
        uint8_t option = static_cast<uint8_t>(temp_option);
        switch (option) {
            case 1:
                add_media_type();
                std::cout << "Choose media type:";
                int media_option;
                std::cin >> media_option;
                switch (media_option) {
                    case 1:
                        add_book_menu();
                        break;
                    case 2:
                        add_movie_menu();
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                view_media_type();
                break;
            case 3:
                exit_interface();
                break;
            default:
                std::cout << "Invalid Option. Try again." << std::endl;
                break;
        }
    }
}

void UserInterface::display_menu() const {
    std::cout << "Choose an option" << std::endl;
    std::cout << "1. Add a Media File" << std::endl;
    std::cout << "2. View Media Files" << std::endl;
    std::cout << "3. Exit." << std::endl;
}

void UserInterface::add_media_type() const {
    std::cout << "1. Add a Book." << std::endl;
    std::cout << "2. Add a Movie." << std::endl;
}

void UserInterface::view_media_type() const {
    std::cout << "1. View Books." << std::endl;
    std::cout << "2. View Movies." << std::endl;
}


void UserInterface::add_book_menu() const {
    std::string title, author, description;
    uint16_t publication_year;
    uint16_t number_of_pages;

    std::cout << "Title: ";
    std::cin >> std::ws;  // Clears any leading whitespace
    std::getline(std::cin, title);  // Use getline to allow multi-word titles

    std::cout << "Author: ";
    std::cin >> std::ws;  // Clears any leading whitespace
    std::getline(std::cin, author); // Use getline to allow multi-word author names

    std::cout << "Publication Year: ";
    std::cin >> publication_year;

    std::cout << "Number of Pages: ";
    std::cin >> number_of_pages;

    // Clear the newline character left by previous std::cin input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Description: ";
    std::getline(std::cin, description);  // Now read the full description

    Book new_book(title, author, publication_year, number_of_pages, description);
    new_book.display_info();
}

void UserInterface::add_movie_menu() const {
    std::string title, author, description;
    uint16_t publication_year;
    uint16_t number_of_minutes;

    std::cout << "Title: ";
    std::cin >> std::ws;  // Clears any leading whitespace
    std::getline(std::cin, title);  // Use getline to allow multi-word titles

    std::cout << "Author: ";
    std::cin >> std::ws;  // Clears any leading whitespace
    std::getline(std::cin, author); // Use getline to allow multi-word author names

    std::cout << "Publication Year: ";
    std::cin >> publication_year;

    std::cout << "Number of Pages: ";
    std::cin >> number_of_minutes;

    // Clear the newline character left by previous std::cin input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Description: ";
    std::getline(std::cin, description);  // Now read the full description

    Movie new_movie(title, author, publication_year, number_of_minutes, description);
    new_movie.display_info();
}

void UserInterface::exit_interface() {
    running = false;
    std::cout << "Exiting interface. Goodbye!" << std::endl;
}
