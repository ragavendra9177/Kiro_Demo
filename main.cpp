#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
    Library lib;

    lib.addBook(Book(1, "C++ Basics", "John", 5));

    lib.addBook(Book(
        1,
        "Python Basics",
        "Mike",
        10)); // BUG

    lib.displayBooks();

    cout << "Fine: "
         << lib.calculateFine(3)
         << endl;

    lib.issueBook(1);

    Book* found =
        lib.searchBook("c++ basics");

    if (found)
    {
        cout << found->title << endl;
    }

    cout << lib.averageBooksPerCategory(0);

    return 0;
}
