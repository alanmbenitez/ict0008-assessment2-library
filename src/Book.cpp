#include "Book.h"
#include <iostream>

void Book::setBookDetails(const std::string& t,
                          const std::string& a,
                          const std::string& i,
                          bool avail,
                          const std::string& date) {
    title = t;
    author = a;
    isbn = i;
    available = avail;
    dateAdded = date;
}

void Book::displayBookDetails() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "ISBN: " << isbn << "\n"
              << "Available: " << (available ? "Yes" : "No") << "\n"
              << "Date Added: " << dateAdded << "\n";
}

bool Book::borrowBook() {
    if (available) {
        available = false;
        return true;
    }
    return false;
}

void Book::returnBook() {
    available = true;
}
