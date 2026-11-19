#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(Book book);

    void displayBooks();

    double calculateFine(int daysLate);

    void issueBook(int id);

    Book* searchBook(std::string title);

    double averageBooksPerCategory(int categories);
};

#endif
