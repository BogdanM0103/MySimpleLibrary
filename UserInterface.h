//
// Created by User on 11/4/2024.
//

#ifndef MYSIMPLELIBRARY_USERINTERFACE_H
#define MYSIMPLELIBRARY_USERINTERFACE_H


class UserInterface {
public:
    // Constructor
    UserInterface();
    void display_menu() const;
    void run();
private:
    bool running;
    void add_book();
    void add_movie();
    void exit_interface();
};


#endif //MYSIMPLELIBRARY_USERINTERFACE_H
