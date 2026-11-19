#include <iostream>
#include "Library.h"

using namespace std;

Book::Book(int id, string title, string author, int quantity)
{
    this->id = id;
    this->title = title;
    this->author = author;
    this->quantity = quantity;
}

void Library::addBook(Book book)
{
    books.push_back(book);
}

void Library::displayBooks()
{
    for (auto book : books)
    {
        cout << book.id << " "
             << book.title << " "
             << book.author << " "
             << book.quantity << endl;
    }
}

double Library::calculateFine(int daysLate)
{
    return daysLate * 2; // BUG
}

void Library::issueBook(int id)
{
    for (auto &book : books)
    {
        if (book.id == id)
        {
            book.quantity--; // BUG
            cout << "Book issued" << endl;
            return;
        }
    }

    cout << "Book not found" << endl;
}

Book* Library::searchBook(string title)
{
    for (auto &book : books)
    {
        if (book.title == title) // BUG
        {
            return &book;
        }
    }

    return nullptr;
}

double Library::averageBooksPerCategory(int categories)
{
    return books.size() / categories; // BUG
}
