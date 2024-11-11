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
                // switch (media_option) {
                //     case 1:
                //         add_book_menu();
                //         break;
                //     case 2:
                //         add_movie_menu();
                //         break;
                //     case 3:
                //         add_song_menu();
                //         break;
                //     default:
                //         break;
                // }
                break;
            case 2:
                view_media_type();
                std::cout << "Choose media type:" << std::endl;
                std::cin >> media_option;
                switch (media_option) {
                    case 1:
                        view_books();
                        break;
                    case 2:
                        view_movies();
                        break;
                    case 3:
                        view_songs();
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                duplicate_media_type();
                std::cout << "Choose media type:" << std::endl;
                std::cin >> media_option;
                switch (media_option) {
                    case 1:
                        duplicate_book();
                        break;
                    case 2:
                        duplicate_movie();
                        break;
                    case 3:
                        duplicate_song();
                        break;
                    default:
                        break;
                }
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


void UserInterface::add_book_menu() {
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

    // Allocate a new Book Object and add the pointer to the vector
    Book* new_book = new Book(title, author, publication_year, number_of_pages, description);
    books.push_back(new_book);

    std::cout << "Book Added Successfully!" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void UserInterface::add_movie_menu() {
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

    std::cout << "Number of Minutes: ";
    std::cin >> number_of_minutes;

    // Clear the newline character left by previous std::cin input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Description: ";
    std::getline(std::cin, description);  // Now read the full description

    // We store pointers here
    Movie* new_movie = new Movie(title, author, publication_year, number_of_minutes, description);
    // new_movie->display_info();
    movies.push_back(new_movie);

    std::cout << "Movie Added Successfully!" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void UserInterface::add_song_menu() {
    std::string title, author, format;
    uint16_t publication_year;
    uint32_t number_of_minutes;

    std::cout << "Title: ";
    std::cin >> std::ws;
    std::getline(std::cin, title);

    std::cout << "Author: ";
    std::cin >> std::ws;
    std::getline(std::cin, author);

    std::cout << "Publication Year: ";
    std::cin >> publication_year;
    std::cout << "Number of Minutes: ";
    std::cin >> number_of_minutes;

    std::cout << "Format: ";
    std::cin >> std::ws;
    std::getline(std::cin, format);
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Song* new_song = new Song(title, author, publication_year, number_of_minutes, format);
    songs.push_back(new_song);

    // We store pointers here
    std::cout << "Song Added Successfully!" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void UserInterface::view_books() {
    if (books.empty()) {
        std::cout << "No more books." << std::endl;
        return;
    }

    for (const auto& book : books) {
        book->display_info();
        std::cout << "-------------------------------" << std::endl;
    }
}

void UserInterface::view_movies() {
    if (movies.empty()) {
        std::cout << "No movies." << std::endl;
        return;
    }

    for (const auto& movie : movies) {
        movie->display_info();
        std::cout << "-------------------------------" << std::endl;
    }
}

void UserInterface::view_songs() {
    if (songs.empty()) {
        std::cout << "No more songs." << std::endl;
        return;
    }

    for (const auto& song : songs) {
        song->display_info();
        std::cout << "------------------------------" << std::endl;
    }
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

void UserInterface::duplicate_book() {
    if (books.empty()) {
        std::cout << "Nothing to duplicate.." << std::endl;
        return;
    }

    std::cout << "Enter Book Title you want to duplicate:";
    std::string title;
    std::cin >> std::ws; // Clear any leading whitespace
    std::getline(std::cin, title); // Read the full title

    auto it = std::find_if(books.begin(), books.end(), [&title](Book* book) {
        return *book->get_title() == title;
    });

    if (it != books.end()) {
        Book* duplicate_book = new Book(**it);
        books.push_back(duplicate_book);
        std::cout << "Book " << title << " duplicated successfully!" << std::endl;
    } else {
        std::cout << "No such book." << std::endl;
    }
}

void UserInterface::duplicate_movie() {
    if (movies.empty()) {
        std::cout << "Nothing to duplicate.." << std::endl;
        return;
    }

    std::cout << "Enter Movie Title you want to duplicate:";
    std::string title;
    std::cin >> std::ws; // Clear any leading whitespace
    std::getline(std::cin, title); // Read the full title

    auto it = std::find_if(movies.begin(), movies.end(), [&title](Movie* movie) {
        return *movie->get_title() == title;
    });

    if (it != movies.end()) {
        Movie* duplicate_movie = new Movie(**it);
        movies.push_back(duplicate_movie);
        std::cout << "Movie " << title << " duplicated successfully!" << std::endl;
    } else {
        std::cout << "No such movie." << std::endl;
    }
}

void UserInterface::duplicate_song() {
    if (songs.empty()) {
        std::cout << "Nothing to duplicate.." << std::endl;
        return;
    }

    std::cout << "Enter Song Title you want to duplicate:";
    std::string title;
    std::cin >> std::ws; // Clear any leading whitespace
    std::getline(std::cin, title); // Read the full title

    auto it = std::find_if(songs.begin(), songs.end(), [&title](Song* song) {
        return *song->get_title() == title;
    });

    if (it != songs.end()) {
        Song* duplicate_song = new Song(**it);
        songs.push_back(duplicate_song);
        std::cout << "Song " << title << " duplicated successfully!" << std::endl;
    } else {
        std::cout << "No such song." << std::endl;
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

        auto book_it = std::find_if(books.begin(), books.end(), [&title](Book* book) {
            return *book->get_title() == title;
        });
        if (book_it != books.end() && *book_it) {
            favorites.push_back(static_cast<MediaFile*>(std::move(*book_it)));  // Cast to MediaFile* and move
            *book_it = nullptr;  // Set original pointer to nullptr
            std::cout << "Book \"" << title << "\" moved to favorites." << std::endl;
            return;
        }

        auto movie_it = std::find_if(movies.begin(), movies.end(), [&title](Movie* movie) {
            return *movie->get_title() == title;
        });
        if (movie_it != movies.end() && *movie_it) {
            favorites.push_back(static_cast<MediaFile*>(std::move(*movie_it)));  // Cast to MediaFile* and move
            *movie_it = nullptr;  // Set original pointer to nullptr
            std::cout << "Movie \"" << title << "\" moved to favorites." << std::endl;
            return;
        }

        auto song_it = std::find_if(songs.begin(), songs.end(), [&title](Song* song) {
            return *song->get_title() == title;
        });
        if (song_it != songs.end() && *song_it) {
            favorites.push_back(std::move(*song_it));  // Cast to MediaFile* and move
            *song_it = nullptr;  // Set original pointer to nullptr
            std::cout << "Song \"" << title << "\" moved to favorites." << std::endl;
            // return;
        }
    }
}

void UserInterface::view_favorites() {
    if (favorites.empty()) {
        std::cout << "No favorites found." << std::endl;
    }

    for (auto favorite : favorites) {
        favorite->display_info();
        std::cout << "-------------------------------" << std::endl;
    }
}
