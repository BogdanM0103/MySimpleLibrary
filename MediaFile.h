#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <cstdint>
#include <string>

class MediaFile {
public:
    // Constructor
    MediaFile(const std::string& title, const std::string& author, uint16_t year);
    // Copy Constructor
    MediaFile(const MediaFile& other);
    // Move Constructor
    MediaFile(const MediaFile&& other) noexcept;
    // Destructor
    virtual ~MediaFile(); // Make destructor virtual
    // method for displaying basic information about the file
    virtual void display_info() const; // Declare display_info as a virtual function
    // // Virtual + operator for derived classes to override
    // virtual MediaFile operator+(const MediaFile& other) const;

private:
    mutable std::string* title; // Pointer member variable
    mutable std::string* author; // Pointer member variable
    uint16_t publication_year;

};

#endif //MEDIAFILE_H
