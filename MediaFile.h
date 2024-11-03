#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <string>

class MediaFile {
public:
    // Constructor
    MediaFile(const std::string& title, const std::string& author, int year);

    // Copy constructor
    MediaFile(const MediaFile& other);

    // Move constructor
    MediaFile(MediaFile&& other) noexcept;

    // Destructor
    ~MediaFile();

    // Method to display information about the media file
    void display_info() const;

private:
    std::string* title;  // Pointer member variable
    std::string* author; // Pointer member variable
    int year;
};

#endif //MEDIAFILE_H
