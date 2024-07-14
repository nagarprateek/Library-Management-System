#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Patron.h"
#include <vector>

class Library {
public:
    void addBook(const Book& book);
    void addPatron(const Patron& patron);

    void displayBookDetails(int bookId) const;
    void displayPatronDetails(int patronId) const;

    void checkOutBook(int bookId, int patronId, int quantity, double price);
    void returnBook(int bookId, int patronId, int quantity);

    void saveData() const;
    void loadData();

    void showAllBooks() const;    // New method
    void showAllPatrons() const;  // New method

private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
};

#endif // LIBRARY_H
