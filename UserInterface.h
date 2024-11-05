//
// Created by User on 11/4/2024.
//

#ifndef MYSIMPLELIBRARY_USERINTERFACE_H
#define MYSIMPLELIBRARY_USERINTERFACE_H
#include <cstdint>
#include <vector>

#include "Book.h"
#include "Movie.h"


class UserInterface {
public:
    // Constructor
    UserInterface();
    void display_menu();
    void add_media_type();
    void view_media_type();
    void add_book_menu();
    void add_movie_menu();
    void view_books();


    void view_movies();

    void run();
private:
    std::vector<Book*> books;
    std::vector<Movie*> movies;
    bool running;
    void exit_interface();
};


#endif //MYSIMPLELIBRARY_USERINTERFACE_H
