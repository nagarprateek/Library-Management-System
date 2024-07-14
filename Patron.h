#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include <fstream>

class Patron {
public:
    Patron(int id, const std::string& name);
    Patron();

    int getId() const;
    std::string getName() const;
    std::vector<int> getCheckedOutBooks() const;

    void checkOutBook(int bookId, int quantity);
    void returnBook(int bookId, int quantity);

    void displayDetails() const;

    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);

private:
    int id;
    std::string name;
    std::vector<std::pair<int, int>> checkedOutBooks; // pair of bookId and quantity
};

#endif // PATRON_H
