
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
    void setBookDetails(const std::string& t,
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

    // Show the book information
    void displayBookDetails() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "ISBN: " << isbn << "\n"
                  << "Available: " << (available ? "Yes" : "No") << "\n"
                  << "Date Added: " << dateAdded << "\n";
    }

    // Borrow the book (only if available)
    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    // Return the book
    void returnBook() {
        available = true;
    }
};

struct Library {
    Book books[5];

    // Sort array by ISBN (ascending)
    void sortBookData() {
        std::sort(std::begin(books), std::end(books),
                  [](const Book& a, const Book& b) {
                      return a.isbn < b.isbn;
                  });
    }

    // Find book index by ISBN, return -1 if not found
    int findByIsbn(const std::string& id) {
        for (int i = 0; i < 5; ++i) {
            if (books[i].isbn == id) return i;
        }
        return -1;
    }

    // Try to borrow by ISBN
    bool borrowByIsbn(const std::string& id) {
        int idx = findByIsbn(id);
        if (idx == -1) {
            std::cout << "Error: Book not found.\n";
            return false;
        }
        if (!books[idx].available) {
            std::cout << "Error: Book is already borrowed.\n";
            return false;
        }
        books[idx].borrowBook();
        std::cout << "Success: You borrowed \"" << books[idx].title << "\".\n";
        return true;
    }
};

int main() {
    Library lib;

    // Initialize 5 books
    lib.books[0].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", true, "2024-03-10");
    lib.books[1].setBookDetails("The Pragmatic Programmer", "Andrew Hunt", "9780201616224", true, "2023-11-21");
    lib.books[2].setBookDetails("Design Patterns", "GoF", "9780201633610", true, "2022-05-05");
    lib.books[3].setBookDetails("You Don't Know JS", "Kyle Simpson", "9781491904244", true, "2024-07-18");
    lib.books[4].setBookDetails("C++ Primer", "Lippman", "9780321714114", true, "2021-08-01");

    // Sort by ISBN before we start
    lib.sortBookData();

    std::cout << "Welcome to Community Library!\n";
    std::cout << "Enter an ISBN to borrow a book (0 to exit).\n\n";

    // Simple loop
    while (true) {
        std::cout << "ISBN: ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "0") {
            std::cout << "Goodbye!\n";
            break;
        }

        lib.borrowByIsbn(input);
        std::cout << "\n";
    }

    return 0;
}
