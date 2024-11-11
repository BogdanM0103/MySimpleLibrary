//
// Created by User on 11/4/2024.
//

#include <iostream>
#include "UserInterface.h"

#include <algorithm>
#include <cstdint>
#include <limits>

#include "Book.h"
#include "Movie.h"
#include "Song.h"

UserInterface::UserInterface() : running(true) {
    std::cout << "UserInterface Constructor called" << std::endl;
}


UserInterface::~UserInterface() {
    std::cout << "UserInterface Destructor called" << std::endl;
    free_books();
    free_movies();
    free_songs();
}

void UserInterface::run() {
    int temp_option;
    while (running) {
        display_menu();
        std::cout << "Enter your option: ";
        std::cin >> temp_option;

        if (std::cin.fail() || temp_option < 1 || temp_option > 6) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }
        uint8_t option = static_cast<uint8_t>(temp_option);
        int media_option;
        switch (option) {
            case 1:
                add_media_type();
                std::cout << "Choose media type:";
                std::cin >> media_option;
                add_media(media_option);
                break;
            case 2:
                view_media_type();
                std::cout << "Choose media type:" << std::endl;
                std::cin >> media_option;
                view_media(media_option);
                break;
            case 3:
                duplicate_media_type();
                std::cout << "Choose media type:" << std::endl;
                std::cin >> media_option;
                duplicate_media(media_option);
                break;
            case 4:
                // Add to favorites
                add_to_favorites_menu();
                break;
            case 5:
                // View favorites
                view_favorites();
                break;
            case 6:
                exit_interface();
                break;
            default:
                std::cout << "Invalid Option. Try again." << std::endl;
                break;
        }
    }
}

void UserInterface::display_menu() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Choose an option" << std::endl;
    std::cout << "1. Add a Media File" << std::endl;
    std::cout << "2. View Media Files" << std::endl;
    std::cout << "3. Duplicate Media Files" << std::endl;
    std::cout << "4. Add to favorites" << std::endl;
    std::cout << "5. View favorites" << std::endl;
    std::cout << "6. Exit." << std::endl;
}

void UserInterface::add_media_type() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. Add a Book." << std::endl;
    std::cout << "2. Add a Movie." << std::endl;
    std::cout << "3. Add a Song" << std::endl;
}

void UserInterface::view_media_type() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. View Books." << std::endl;
    std::cout << "2. View Movies." << std::endl;
    std::cout << "3. View Songs." << std::endl;
}

void UserInterface::exit_interface() {
    // Turning this variable to false will lead to the interface shutting down..
    running = false;
    std::cout << "Exiting interface. Goodbye!" << std::endl;
}

void UserInterface::free_books() {
    // Free allocated memory for books
    if (!books.empty()) {
        for (const auto& book : books) {
            delete book;
        }
        std::cout << "Freed books from Heap.." << std::endl;
    }

}

void UserInterface::free_movies() {
    // Free allocated memory for movies
    if (!movies.empty()) {
        for (const auto& movie : movies) {
            delete movie;
        }
        std::cout << "Freed movies from Heap.." << std::endl;
    }

}

void UserInterface::add_media(uint8_t option) {
    std::string title, author, description;
    uint16_t publication_year;

    std::cout << "Title: ";
    std::cin >> std::ws;  // Clears any leading whitespace
    std::getline(std::cin, title);  // Use getline to allow multi-word titles

    std::cout << "Author: ";
    std::cin >> std::ws;  // Clears any leading whitespace
    std::getline(std::cin, author); // Use getline to allow multi-word author names

    std::cout << "Publication Year: ";
    std::cin >> publication_year;

    switch (option) {
        case 1: {  // Book case
            uint16_t number_of_pages;
            std::cout << "Number of Pages: ";
            std::cin >> number_of_pages;

            std::cout << "Description: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, description);

            Book* new_book = new Book(title, author, publication_year, number_of_pages, description);
            books.push_back(new_book);

            std::cout << "Book Added Successfully!" << std::endl;
            std::cout << "-------------------------------" << std::endl;
            break;
        }
        case 2: {  // Movie case
            uint16_t number_of_minutes;
            std::cout << "Number of Minutes: ";
            std::cin >> number_of_minutes;

            std::cout << "Description: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, description);

            Movie* new_movie = new Movie(title, author, publication_year, number_of_minutes, description);
            movies.push_back(new_movie);

            std::cout << "Movie Added Successfully!" << std::endl;
            std::cout << "-------------------------------" << std::endl;
            break;
        }
        case 3: {  // Song case
            uint32_t number_of_minutes;
            std::string format;
            std::cout << "Number of Minutes: ";
            std::cin >> number_of_minutes;

            std::cout << "Format: ";
            std::cin >> std::ws;
            std::getline(std::cin, format);

            Song* new_song = new Song(title, author, publication_year, number_of_minutes, format);
            songs.push_back(new_song);

            std::cout << "Song Added Successfully!" << std::endl;
            std::cout << "-------------------------------" << std::endl;
            break;
        }
    }
}

void UserInterface::view_media(uint8_t media_option) {
    bool is_empty = true;
    switch (media_option) {
        case 1:
            if (books.empty()) {
                std::cout << "No more books." << std::endl;
                return;
            }
            for (const auto& book : books) {
                if (book) {
                    book->display_info();
                    is_empty = false;
                }
            }
            break;

        case 2:
            if (movies.empty()) {
                std::cout << "No more movies." << std::endl;
                return;
            }
            for (const auto& movie : movies) {
                if (movie) {
                    movie->display_info();
                    is_empty = false;
                }

            }
            break;

        case 3:
            if (songs.empty()) {
                std::cout << "No more songs." << std::endl;
                return;
            }
            for (const auto& song : songs) {
                if (song) {
                    song->display_info();
                    is_empty = false;
                }
            }
            break;

        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
    if (is_empty == true) {
        std::cout << "Nothing to view.." << std::endl;
    }
}

void UserInterface::free_songs() {
    // Free allocated memory for songs
    if (!songs.empty()) {
        for (const auto& song : songs) {
            delete song;
        }
        std::cout << "Freed songs from Heap.." << std::endl;
    }
}

void UserInterface::duplicate_media_type() {
    std::cout << "Choose media type:" << std::endl;
    std::cout << "1. Book" << std::endl;
    std::cout << "2. Movie" << std::endl;
    std::cout << "3. Song" << std::endl;
}

void UserInterface::duplicate_media(uint8_t media_option) {
    switch (media_option) {
        case 1: {  // Book duplication
            if (books.empty()) {
                std::cout << "No more books to duplicate." << std::endl;
                return;
            }

            std::cout << "Enter Book Title you want to duplicate: ";
            std::string book_title;
            std::cin >> std::ws; // Clear any leading whitespace
            std::getline(std::cin, book_title); // Read the full title

            auto it_book = std::find_if(books.begin(), books.end(), [&book_title](Book* book) {
                return *book->get_title() == book_title;
            });

            if (it_book != books.end()) {
                Book* duplicate_book = new Book(**it_book);
                books.push_back(duplicate_book);
                std::cout << "Book \"" << book_title << "\" duplicated successfully!" << std::endl;
            } else {
                std::cout << "No such book." << std::endl;
            }
            break;
        }
        case 2: {  // Movie duplication
            if (movies.empty()) {
                std::cout << "Nothing to duplicate." << std::endl;
                return;
            }

            std::cout << "Enter Movie Title you want to duplicate: ";
            std::string movie_title;
            std::cin >> std::ws; // Clear any leading whitespace
            std::getline(std::cin, movie_title); // Read the full title

            auto it_movie = std::find_if(movies.begin(), movies.end(), [&movie_title](Movie* movie) {
                return *movie->get_title() == movie_title;
            });

            if (it_movie != movies.end()) {
                Movie* duplicate_movie = new Movie(**it_movie);
                movies.push_back(duplicate_movie);
                std::cout << "Movie \"" << movie_title << "\" duplicated successfully!" << std::endl;
            } else {
                std::cout << "No such movie." << std::endl;
            }
            break;
        }
        case 3: {  // Song duplication
            if (songs.empty()) {
                std::cout << "Nothing to duplicate." << std::endl;
                return;
            }

            std::cout << "Enter Song Title you want to duplicate: ";
            std::string song_title;
            std::cin >> std::ws; // Clear any leading whitespace
            std::getline(std::cin, song_title); // Read the full title

            auto it_song = std::find_if(songs.begin(), songs.end(), [&song_title](Song* song) {
                return *song->get_title() == song_title;
            });

            if (it_song != songs.end()) {
                Song* duplicate_song = new Song(**it_song);
                songs.push_back(duplicate_song);
                std::cout << "Song \"" << song_title << "\" duplicated successfully!" << std::endl;
            } else {
                std::cout << "No such song." << std::endl;
            }
            break;
        }
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
}

void UserInterface::add_to_favorites_menu() {
    if (books.empty() && movies.empty() && songs.empty()) {
        std::cout << "No books or movies and songs." << std::endl;
        return;
    } else {
        std::cout << "Enter Media File title to Add:" << std::endl;
        std::string title;
        std::cin >> std::ws;
        std::getline(std::cin, title);

        // Search in books
        auto it_book = std::find_if(books.begin(), books.end(), [&title](Book* book) {
            return *book->get_title() == title;
        });
        if (it_book != books.end() && *it_book) {
            // Manually invoke the move constructor for Book
            Book* moved_book = new Book(std::move(**it_book));
            favorites.push_back(moved_book);  // Add the moved Book as MediaFile* to favorites

            delete *it_book;  // Clean up original
            *it_book = nullptr;  // Set the original pointer to nullptr
            std::cout << "Book \"" << title << "\" moved to favorites." << std::endl;
            return;
        }

        // Search in movies
        auto it_movie = std::find_if(movies.begin(), movies.end(), [&title](Movie* movie) {
            return *movie->get_title() == title;
        });
        if (it_movie != movies.end() && *it_movie) {
            // Manually invoke the move constructor for Movie
            Movie* moved_movie = new Movie(std::move(**it_movie));
            favorites.push_back(moved_movie);  // Add the moved Movie as MediaFile* to favorites

            delete *it_movie;  // Clean up original
            *it_movie = nullptr;  // Set the original pointer to nullptr
            std::cout << "Movie \"" << title << "\" moved to favorites." << std::endl;
            return;
        }

        // Search in songs
        auto it_song = std::find_if(songs.begin(), songs.end(), [&title](Song* song) {
            return *song->get_title() == title;
        });
        if (it_song != songs.end() && *it_song) {
            // Manually invoke the move constructor for Song
            Song* moved_song = new Song(std::move(**it_song));
            favorites.push_back(moved_song);  // Add the moved Song as MediaFile* to favorites

            delete *it_song;  // Clean up original
            *it_song = nullptr;  // Set the original pointer to nullptr
            std::cout << "Song \"" << title << "\" moved to favorites." << std::endl;
            return;
        }

        // If not found in any collection
        std::cout << "Media file with title \"" << title << "\" not found." << std::endl;
    }
}

void UserInterface::view_favorites() {
    if (favorites.empty()) {
        std::cout << "No favorites found." << std::endl;
        return;
    }

    for (auto favorite : favorites) {
        if (favorite) {
            favorite->display_info();
        }
        std::cout << "-------------------------------" << std::endl;
    }
}
