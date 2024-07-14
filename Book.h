#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <fstream>

class Book {
public:
    Book(int id, const std::string& title, const std::string& author, int quantity);
    Book();

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getQuantity() const;
    bool isCheckedOut() const;

    void checkOut(int quantity);
    void returnBook(int quantity);

    void displayDetails() const;

    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);

private:
    int id;
    std::string title;
    std::string author;
    int quantity;
    bool checkedOut;
};

#endif // BOOK_H
