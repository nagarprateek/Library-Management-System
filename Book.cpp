#include "Book.h"
#include <iostream>

Book::Book(int id, const std::string& title, const std::string& author, int quantity)
    : id(id), title(title), author(author), quantity(quantity), checkedOut(false) {}

Book::Book() : id(0), title(""), author(""), quantity(0), checkedOut(false) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getQuantity() const { return quantity; }
bool Book::isCheckedOut() const { return checkedOut; }

void Book::checkOut(int qty) {
    if (quantity >= qty) {
        quantity -= qty;
        checkedOut = true;
    }
}

void Book::returnBook(int qty) {
    quantity += qty;
    if (quantity > 0) {
        checkedOut = false;
    }
}

void Book::displayDetails() const {
    std::cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nQuantity: " << quantity << "\nChecked Out: " << (checkedOut ? "Yes" : "No") << "\n";
}

void Book::save(std::ofstream& outFile) const {
    outFile << id << "\n" << title << "\n" << author << "\n" << quantity << "\n" << checkedOut << "\n";
}

void Book::load(std::ifstream& inFile) {
    inFile >> id;
    inFile.ignore();
    std::getline(inFile, title);
    std::getline(inFile, author);
    inFile >> quantity;
    inFile >> checkedOut;
    inFile.ignore();
}
