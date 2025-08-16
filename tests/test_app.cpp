
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "../src/Book.h"     

// --- Sort function ---
void sortByIsbn(std::vector<Book>& arr) {
    std::sort(arr.begin(), arr.end(),
        [](const Book& a, const Book& b){ return a.isbn < b.isbn; });
}

// --- Validation---
static bool isDigits(const std::string& s){
    return !s.empty() && std::all_of(s.begin(), s.end(),
           [](unsigned char c){ return std::isdigit(c); });
}
static bool looksLikeIsoDate(const std::string& s){
    return s.size()==10 && s[4]=='-' && s[7]=='-';
}
static bool isValidBook(const Book& b){
    if(b.title.empty() || b.author.empty()) return false;
    if(!isDigits(b.isbn)) return false;
    if(!looksLikeIsoDate(b.dateAdded)) return false;
    return true;
}

static void printBook(const Book& b) {
    std::cout << "Title: " << b.title
              << " | Author: " << b.author
              << " | ISBN: " << b.isbn
              << " | Available: " << (b.available ? "Yes" : "No")
              << " | DateAdded: " << b.dateAdded << "\n";
}

static void printArray(const std::vector<Book>& arr, const std::string& label) {
    std::cout << label << "\n";
    for(const auto& b : arr) std::cout << b.isbn << " ";
    std::cout << "\n";
}

int main(){
    std::cout << "=== Assessment 3 Test Application ===\n\n";

    // --- Correct initialisation (3 books) ---
    Book b1, b2, b3;
    b1.setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", true,  "2024-03-10");
    b2.setBookDetails("Pragmatic Programmer", "Andrew Hunt", "9780201616224", true, "2023-11-21");
    b3.setBookDetails("Design Patterns", "GoF", "9780201633610", false, "2022-05-05");

    std::cout << "[Correct initialisation]\n";
    printBook(b1); printBook(b2); printBook(b3);
    std::cout << "Valid? " << (isValidBook(b1) && isValidBook(b2) && isValidBook(b3) ? "Yes" : "No") << "\n\n";

    // --- Incorrect initialisation (3 books) ---
    Book i1, i2, i3;
    i1.setBookDetails("", "Unknown", "9781491904244", true, "2024-07-18");          // empty title
    i2.setBookDetails("Bad ISBN", "Someone", "ISBN-ABC", true, "2024-01-01");       // non-digit ISBN
    i3.setBookDetails("Bad Date", "Someone", "9780321714114", true, "2024/13/99");  // bad date format

    std::cout << "[Incorrect initialisation]\n";
    printBook(i1); std::cout << "Valid? " << (isValidBook(i1) ? "Yes" : "No") << "\n";
    printBook(i2); std::cout << "Valid? " << (isValidBook(i2) ? "Yes" : "No") << "\n";
    printBook(i3); std::cout << "Valid? " << (isValidBook(i3) ? "Yes" : "No") << "\n\n";

    // --- Arrays of 3 books: ascending, descending, mixed ---
    std::vector<Book> asc  = {b1, b2, b3};
    std::vector<Book> desc = {b3, b2, b1};
    std::vector<Book> mix  = {b2, b1, b3};

    // Before sort
    printArray(asc,  "ASC  (before sort):");
    printArray(desc, "DESC (before sort):");
    printArray(mix,  "MIX  (before sort):");
    std::cout << "\n";

    // Sort
    sortByIsbn(asc);
    sortByIsbn(desc);
    sortByIsbn(mix);

    // After sort
    printArray(asc,  "ASC  (after sort):");
    printArray(desc, "DESC (after sort):");
    printArray(mix,  "MIX  (after sort):");

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
