//
// Created by Bogdan on 11/4/2024.
//

#ifndef MEDIAFILE_H
#define MEDIAFILE_H
#include <string>

class MediaFile {
    public:
        MediaFile(const std::string& title, const std::string& author, int year);
        ~MediaFile();
    private:
        std::string* title;
        std::string* author;
        int year;
};

#endif //MEDIAFILE_H
