//
// Created by User on 11/4/2024.
//

#ifndef MYSIMPLELIBRARY_USERINTERFACE_H
#define MYSIMPLELIBRARY_USERINTERFACE_H
#include <cstdint>
#include <vector>

#include "Book.h"
#include "Movie.h"
#include "Song.h"


class UserInterface {
public:
    // Constructor
    UserInterface();

    // Destructor
    ~UserInterface();

    // Display main menu of the Interface
    void display_menu();

    // Menu for media type to choose adding
    void add_media_type();

    // Menu for media type to choose viewing
    void view_media_type();

    // Frees book vector from heap
    void free_books();

    // Frees movies vector from heap
    void free_movies();

    void add_media(uint8_t option);

    void view_media(uint8_t option);

    // Free songs
    void free_songs();

    void view_books();

    void view_movies();

    void view_songs();

    void duplicate_media_type();

    void duplicate_media(uint8_t media_option);

    void add_to_favorites_menu();

    void view_favorites();

    // Starts the Interface
    void run();

    // No functionality other than displaying text
    void exit_interface();
private:
    bool running;
    std::vector<Book*> books; // Stores pointers instead of objects
    std::vector<Movie*> movies;
    std::vector<Song*> songs;
    std::vector<MediaFile*> favorites;
};


#endif //MYSIMPLELIBRARY_USERINTERFACE_H
