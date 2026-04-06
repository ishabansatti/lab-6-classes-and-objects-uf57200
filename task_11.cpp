
#include <iostream>
#include <string>
using namespace std;

struct PublisherInfo {
    string name;
    int year;
};

class Book {
private:
    string title;
    string author;
    double price;
    PublisherInfo publisher;
    bool available;
    bool hasPublisher;
    static int totalBooks;

public:
    Book() : title("Unknown"), author("Unknown"), price(1000), publisher({"Unknown", 0}), available(true), hasPublisher(false) {
        totalBooks++;
    }

    Book(string t, string a, double p) : title(t), author(a), price(1000), publisher({"Unknown", 0}), available(true), hasPublisher(false) {
        totalBooks++;
        setPrice(p);
    }

    Book(string t, string a, double p, PublisherInfo pub) : title(t), author(a), price(1000), publisher(pub), available(true), hasPublisher(true) {
        totalBooks++;
        setPrice(p);
    }

    void setPrice(double p) {
        if (p <= 0) {
            cout << "Invalid price! Price must be greater than 0." << endl;
            return;
        }
        price = p;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    bool isAvailable() const {
        return available;
    }

    void checkOut() {
        if (!available) {
            cout << "Error: '" << title << "' is not available." << endl;
            return;
        }
        available = false;
        cout << "'" << title << "' checked out successfully." << endl;
    }

    void returnBook() {
        available = true;
        cout << "'" << title << "' has been returned." << endl;
    }

    void display() const {
        cout << "Title: " << title << " | Author: " << author << " | Price: " << price;
        if (hasPublisher) {
            cout << " | Publisher: " << publisher.name << " (" << publisher.year << ")";
        } else {
            cout << " | No publisher info";
        }
        cout << " | Available: " << (available ? "Yes" : "No") << endl;
    }

    static void showTotal() {
        cout << "Total books in system: " << totalBooks << endl;
    }
};

int Book::totalBooks = 0;

Book cheapest(Book a, Book b) {
    if (a.getPrice() <= b.getPrice()) {
        return a;
    }
    return b;
}

int main() {
    PublisherInfo pearson = {"Pearson", 2008};
    PublisherInfo addison = {"Addison", 1999};

    Book book1("Clean Code", "Robert Martin", 2500, pearson);
    Book book2("The Pragmatic", "Hunt & Thomas", 3200, addison);
    Book book3("Design Patterns", "GoF", 4000);

    book3.setPrice(0);

    cout << "--- All Books ---" << endl;
    book1.display();
    book2.display();
    book3.display();

    book1.checkOut();
    book1.checkOut();
    book1.returnBook();
    book1.checkOut();

    cout << "Cheapest book:" << endl;
    Book cheaper = cheapest(book1, book2);
    cheaper.display();

    Book::showTotal();

    return 0;
}
