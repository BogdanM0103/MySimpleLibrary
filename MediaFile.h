#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <string>

class MediaFile {
public:
    // Constructor
    MediaFile(const std::string& title, const std::string& author, int year);

    // Copy constructor
    MediaFile(const MediaFile& other);

    // Destructor
    ~MediaFile();

private:
    std::string title;  // Direct member variable
    std::string author; // Direct member variable
    int year;
};

#endif //MEDIAFILE_H
