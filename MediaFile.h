#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <string>

class MediaFile {
public:
    MediaFile(const std::string& title, const std::string& author, int year);
    virtual ~MediaFile(); // Make destructor virtual
    virtual void display_info() const; // Declare display_info as a virtual function

private:
    std::string* title; // Pointer member variable
    std::string* author; // Pointer member variable
    int year;
};

#endif //MEDIAFILE_H
