#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int quantity;

    Book(int id, string title, string author, int quantity) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->quantity = quantity;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void displayBooks() {
        for (auto book : books) {
            cout << book.id << " "
                 << book.title << " "
                 << book.author << " "
                 << book.quantity << endl;
        }
    }

    double calculateFine(int daysLate) {
        return daysLate * 2;     // BUG
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                book.quantity--; // BUG
                cout << "Book issued" << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
    }

    Book* searchBook(string title) {
        for (auto &book : books) {
            if (book.title == title) { // BUG
                return &book;
            }
        }
        return nullptr;
    }

    double averageBooksPerCategory(int categories) {
        return books.size() / categories; // BUG
    }
};

int main() {
    Library lib;

    lib.addBook(Book(1, "C++ Basics", "John", 5));
    lib.addBook(Book(1, "Python Basics", "Mike", 10)); // BUG

    lib.displayBooks();

    cout << "Fine: "
         << lib.calculateFine(3)
         << endl;

    lib.issueBook(1);

    Book* found = lib.searchBook("c++ basics");

    if (found)
        cout << found->title << endl;

    cout << lib.averageBooksPerCategory(0);

    return 0;
}
