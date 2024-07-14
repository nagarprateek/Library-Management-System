#include "Library.h"
#include <iostream>
#include <fstream>
#include <iomanip> // For formatted output

void Library::addBook(const Book& book) {
    for (const auto& existingBook : books) {
        if (existingBook.getId() == book.getId()) {
            std::cout << "A book with the same ID already exists. Please enter a different ID.\n";
            return;
        }
    }
    books.push_back(book);
    std::cout << "Book added successfully.\n";
}

void Library::addPatron(const Patron& patron) {
    for (const auto& existingPatron : patrons) {
        if (existingPatron.getId() == patron.getId()) {
            std::cout << "A patron with the same ID already exists. Please enter a different ID.\n";
            return;
        }
    }
    patrons.push_back(patron);
    std::cout << "Patron added successfully.\n";
}

void Library::displayBookDetails(int bookId) const {
    for (const auto& book : books) {
        if (book.getId() == bookId) {
            book.displayDetails();
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::displayPatronDetails(int patronId) const {
    for (const auto& patron : patrons) {
        if (patron.getId() == patronId) {
            patron.displayDetails();
            return;
        }
    }
    std::cout << "Patron not found.\n";
}

void Library::checkOutBook(int bookId, int patronId, int quantity, double price) {
    for (auto& book : books) {
        if (book.getId() == bookId) {
            if (book.getQuantity() >= quantity) {
                for (auto& patron : patrons) {
                    if (patron.getId() == patronId) {
                        book.checkOut(quantity);
                        patron.checkOutBook(bookId, quantity);
                        std::cout << "Book checked out successfully. Total price: $" << price * quantity << "\n";
                        return;
                    }
                }
                std::cout << "Patron not found.\n";
                return;
            } else {
                std::cout << "Insufficient quantity available. Only " << book.getQuantity() << " books available.\n";
                return;
            }
        }
    }
    std::cout << "Book not available or insufficient quantity.\n";
}

void Library::returnBook(int bookId, int patronId, int quantity) {
    for (auto& book : books) {
        if (book.getId() == bookId) {
            for (auto& patron : patrons) {
                if (patron.getId() == patronId) {
                    book.returnBook(quantity);
                    patron.returnBook(bookId, quantity);
                    std::cout << "Book returned successfully.\n";
                    return;
                }
            }
            std::cout << "Patron not found.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::saveData() const {
    std::ofstream bookFile("books.dat");
    std::ofstream patronFile("patrons.dat");

    if (bookFile.is_open()) {
        bookFile << books.size() << "\n";
        for (const auto& book : books) {
            book.save(bookFile);
        }
        bookFile.close();
    }

    if (patronFile.is_open()) {
        patronFile << patrons.size() << "\n";
        for (const auto& patron : patrons) {
            patron.save(patronFile);
        }
        patronFile.close();
    }
}

void Library::loadData() {
    std::ifstream bookFile("books.dat");
    std::ifstream patronFile("patrons.dat");

    if (bookFile.is_open()) {
        int bookCount;
        bookFile >> bookCount;
        books.resize(bookCount);
        for (int i = 0; i < bookCount; ++i) {
            books[i].load(bookFile);
        }
        bookFile.close();
    }

    if (patronFile.is_open()) {
        int patronCount;
        patronFile >> patronCount;
        patrons.resize(patronCount);
        for (int i = 0; i < patronCount; ++i) {
            patrons[i].load(patronFile);
        }
        patronFile.close();
    }
}

void Library::showAllBooks() const {
    std::cout << std::setw(10) << "Book ID" << std::setw(30) << "Title" << std::setw(30) << "Author" << std::setw(10) << "Quantity" << "\n";
    std::cout << std::string(80, '-') << "\n";
    for (const auto& book : books) {
        std::cout << std::setw(10) << book.getId() << std::setw(30) << book.getTitle() << std::setw(30) << book.getAuthor() << std::setw(10) << book.getQuantity() << "\n";
    }
}

void Library::showAllPatrons() const {
    std::cout << std::setw(10) << "Patron ID" << std::setw(30) << "Name" << "\n";
    std::cout << std::string(40, '-') << "\n";
    for (const auto& patron : patrons) {
        std::cout << std::setw(10) << patron.getId() << std::setw(30) << patron.getName() << "\n";
    }
}
