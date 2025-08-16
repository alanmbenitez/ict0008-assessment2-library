#include "Library.h"
#include <iostream>
#include <string>

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
