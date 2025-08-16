#include "Library.h"
#include <algorithm>
#include <iostream>

void Library::sortBookData() {
    std::sort(books.begin(), books.end(),
              [](const Book& a, const Book& b) {
                  return a.isbn < b.isbn;
              });
}

int Library::findByIsbn(const std::string& id) const {
    for (int i = 0; i < static_cast<int>(books.size()); ++i) {
        if (books[i].isbn == id) return i;
    }
    return -1;
}

bool Library::borrowByIsbn(const std::string& id) {
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
