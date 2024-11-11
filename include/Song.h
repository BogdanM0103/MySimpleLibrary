//
// Created by Bogdan on 11/6/2024.
//

#ifndef SONG_H
#define SONG_H
#include "MediaFile.h"


class Song : public MediaFile{
public:
    // Constructor
    Song(const std::string& title, const std::string& author, const uint16_t publication_year, const uint32_t duration_in_minutes, const std::string& format);

    // Destructor
    ~Song();

    // Copy Constructor
    Song(const Song& other);

    // Move Constructor
    Song(const Song &&other);

    const std::string* get_title() const;
    void display_info() const override;

private:
    uint32_t duration_in_minutes;
    std::string* format;
};



#endif //SONG_H
