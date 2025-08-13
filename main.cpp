
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
    std::string dateAdded; // simple text to keep it easy

    // Assign values to attributes
    void setBookDetails() {
       
    }

    // Show the book information
    void displayBookDetails() const {
       
    }

    // Borrow the book (only if available)
    bool borrowBook() {
        
    }

    // Return the book
    void returnBook() {
       
    }
};

struct Library {
    Book books[5];

    // Sort array by ISBN (ascending)
    void sortBookData() {
        
    }

    // Find book index by ISBN, return -1 if not found
    int findByIsbn(const std::string& id) {
       
    }

    // Try to borrow by ISBN
    bool borrowByIsbn(const std::string& id) {
       
    }
};
