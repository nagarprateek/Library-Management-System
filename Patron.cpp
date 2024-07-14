#include "Patron.h"
#include <iostream>
#include <algorithm>

Patron::Patron(int id, const std::string& name)
    : id(id), name(name) {}

Patron::Patron() : id(0), name("") {}

int Patron::getId() const { return id; }
std::string Patron::getName() const { return name; }
std::vector<int> Patron::getCheckedOutBooks() const { 
    std::vector<int> bookIds;
    for (const auto& pair : checkedOutBooks) {
        bookIds.push_back(pair.first);
    }
    return bookIds;
}

void Patron::checkOutBook(int bookId, int quantity) {
    checkedOutBooks.push_back(std::make_pair(bookId, quantity));
}

void Patron::returnBook(int bookId, int quantity) {
    auto it = std::find_if(checkedOutBooks.begin(), checkedOutBooks.end(),
                           [bookId](const std::pair<int, int>& pair) { return pair.first == bookId; });
    if (it != checkedOutBooks.end()) {
        if (it->second > quantity) {
            it->second -= quantity;
        } else {
            checkedOutBooks.erase(it);
        }
    }
}

void Patron::displayDetails() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nChecked Out Books: ";
    for (const auto& pair : checkedOutBooks) {
        std::cout << "(" << pair.first << ", Quantity: " << pair.second << ") ";
    }
    std::cout << "\n";
}

void Patron::save(std::ofstream& outFile) const {
    outFile << id << "\n" << name << "\n";
    outFile << checkedOutBooks.size() << "\n";
    for (const auto& pair : checkedOutBooks) {
        outFile << pair.first << " " << pair.second << " ";
    }
    outFile << "\n";
}

void Patron::load(std::ifstream& inFile) {
    int bookCount;
    inFile >> id;
    inFile.ignore();
    std::getline(inFile, name);
    inFile >> bookCount;
    checkedOutBooks.resize(bookCount);
    for (int i = 0; i < bookCount; ++i) {
        inFile >> checkedOutBooks[i].first >> checkedOutBooks[i].second;
    }
    inFile.ignore();
}
