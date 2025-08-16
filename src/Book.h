#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    bool        available{true};
    std::string dateAdded; // simple text

    void setBookDetails(const std::string& t,
                        const std::string& a,
                        const std::string& i,
                        bool avail,
                        const std::string& date);

    void displayBookDetails() const;
    bool borrowBook();
    void returnBook();
};

#endif // BOOK_H
