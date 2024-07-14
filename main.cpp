#include "Library.h"
#include <iostream>


void displayMenu() {
    std::cout << "\n";
    std::cout << "Library Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add Patron\n";
    std::cout << "3. Display Book Details\n";
    std::cout << "4. Display Patron Details\n";
    std::cout << "5. Check Out Book\n";
    std::cout << "6. Return Book\n";
    std::cout << "7. Save and Exit\n";
    std::cout << "Enter your choice: ";
    std::cout << "\n";
}

int main() {
    Library library;
    library.loadData();

    int choice, bookId, patronId, quantity;
    std::string title, author, name;
    double price;
    char moreBooks;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Book ID: ";
                std::cin >> bookId;
                std::cin.ignore();
                std::cout << "Enter Book Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Book Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter Book Quantity: ";
                std::cin >> quantity;
                library.addBook(Book(bookId, title, author, quantity));
                break;

            case 2:
                std::cout << "Enter Patron ID: ";
                std::cin >> patronId;
                std::cin.ignore();
                std::cout << "Enter Patron Name: ";
                std::getline(std::cin, name);
                library.addPatron(Patron(patronId, name));
                break;

            case 3:
                std::cout << "Enter Book ID: ";
                std::cin >> bookId;
                library.displayBookDetails(bookId);
                break;

            case 4:
                std::cout << "Enter Patron ID: ";
                std::cin >> patronId;
                library.displayPatronDetails(patronId);
                break;

            case 5:
                do {
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookId;
                    std::cout << "Enter Patron ID: ";
                    std::cin >> patronId;
                    std::cout << "Enter Quantity: ";
                    std::cin >> quantity;
                    std::cout << "Enter Price per Book: ";
                    std::cin >> price;
                    library.checkOutBook(bookId, patronId, quantity, price);

                    std::cout << "Do you want to check out more books? (y/n): ";
                    std::cin >> moreBooks;
                } while (moreBooks == 'y' || moreBooks == 'Y');
                break;

            case 6:
                std::cout << "Enter Book ID: ";
                std::cin >> bookId;
                std::cout << "Enter Patron ID: ";
                std::cin >> patronId;
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                library.returnBook(bookId, patronId, quantity);
                break;

            case 7:
                library.saveData();
                std::cout << "Data saved. Exiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
