//
// Created by User on 11/4/2024.
//

#ifndef MYSIMPLELIBRARY_USERINTERFACE_H
#define MYSIMPLELIBRARY_USERINTERFACE_H
#include <cstdint>


class UserInterface {
public:
    // Constructor
    UserInterface();
    void display_menu() const;
    void add_media_type() const;
    void view_media_type() const;
    void add_book_menu() const;
    void add_movie_menu() const;



    void run();
private:
    uint16_t inputID;
    bool running;
    void exit_interface();
};


#endif //MYSIMPLELIBRARY_USERINTERFACE_H
