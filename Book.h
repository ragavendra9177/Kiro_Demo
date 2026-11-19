#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    int quantity;

    Book(int id, std::string title, std::string author, int quantity);
};

#endif
