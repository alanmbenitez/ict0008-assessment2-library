#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <array>
#include <string>

class Library {
public:
    std::array<Book, 5> books;

    void sortBookData();                      // sort by ISBN 
    int  findByIsbn(const std::string& id) const; // -1 if not found
    bool borrowByIsbn(const std::string& id); // prints messages & returns success
};

#endif
