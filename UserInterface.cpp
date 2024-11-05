//
// Created by User on 11/4/2024.
//

#include <iostream>
#include "UserInterface.h"

#include <cstdint>
#include <limits>

UserInterface::UserInterface() : running(true) {
    std::cout << "UserInterface Constructor called" << std::endl;
}

void UserInterface::run() {
    int temp_option;
    while (running) {
        display_menu();
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
                add_book();
                break;
            case 2:
                add_movie();
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

void UserInterface::add_book() {

}

void UserInterface::add_movie() {

}

void UserInterface::exit_interface() {
    running = false;
    std::cout << "Exiting interface. Goodbye!" << std::endl;
}
