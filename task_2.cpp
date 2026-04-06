
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    double price;

    void display() const {
        cout << "Title: " << title << " | Author: " << author << " | Price: " << price << endl;
    }
};

int main() {
    Book books[3];

    books[0].title = "Clean Code";
    books[0].author = "Robert Martin";
    books[0].price = 2500;

    books[1].title = "The Pragmatic Programmer";
    books[1].author = "Andrew Hunt";
    books[1].price = 3200;

    books[2].title = "Design Patterns";
    books[2].author = "GoF";
    books[2].price = 4000;

    for (int i = 0; i < 3; i++) {
        books[i].display();
    }

    return 0;
}
