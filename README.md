# ICT0008 Assessment 3 – Community Library (C++)

This is my assessment project for ICT0008.  
It is a simple C++ app to manage books in a small community library.  
The program lets the user borrow a book by typing the ISBN, checks if it is available, and prints messages.  
I also included a test program to show that my `Book` and `Library` classes work correctly.

---

## Features
* Store book data: **title, author, ISBN, availability, date added**  
* Show details of a book  
* Borrow and return books  
* Library can **sort books by ISBN**  
* Main loop: user enters ISBN, borrow if possible, exit with `0`  
* Extra: simple test app (`tests/test_app.cpp`) to check correct and incorrect initialisation, sorting etc.

---

## Requirements
* **C++17** or newer  
* A terminal or shell (Linux/Mac) or PowerShell (Windows)  
* Optional: Git and GitHub for version control  

---

## How to Compile and Run

### 1. Compile the main library app
```bash
g++ -std=c++17 -O2 -o library_app src/*.cpp
./library_app

---

### 2. Compile and run the test app

g++ -std=c++17 -O2 -o test_app tests/test_app.cpp src/Book.cpp
./test_app

