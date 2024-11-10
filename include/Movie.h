//
// Created by User on 11/4/2024.
//

#ifndef MYSIMPLELIBRARY_MOVIE_H
#define MYSIMPLELIBRARY_MOVIE_H

#include "MediaFile.h"

class Movie: public MediaFile {
public:
    // Constructor
    Movie(const std::string& title, const std::string& author, const uint16_t publication_year, const uint16_t length, const std::string& description);

    // Copy Constructor
    Movie(const Movie& other);

    // Move Constructor
    Movie(Movie&& other) noexcept;

    // Destructor
    ~Movie();

    const std::string* get_title() const;
    void display_info() const override;
private:
    int length;
    std::string* description;
};

#endif //MYSIMPLELIBRARY_MOVIE_H
