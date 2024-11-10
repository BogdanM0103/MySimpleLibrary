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

    // Handles adding books
    void add_book_menu();

    // Frees book vector from heap
    void free_books();

    // Add movie
    void add_movie_menu();
    // Frees movies vector from heap
    void free_movies();

    // Add song
    void add_song_menu();
    // Free songs
    void free_songs();

    void view_books();

    void view_movies();

    void view_songs();

    void duplicate_media_type();

    void duplicate_book();

    void duplicate_movie();

    void duplicate_song();

    // Starts the Interface
    void run();

    // No functionality other than displaying text
    void exit_interface();
private:
    bool running;
    std::vector<Book*> books; // Stores pointers instead of objects
    std::vector<Movie*> movies;
    std::vector<Song*> songs;
};


#endif //MYSIMPLELIBRARY_USERINTERFACE_H
