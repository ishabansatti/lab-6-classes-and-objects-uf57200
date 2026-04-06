
#include <iostream>
#include <string>
using namespace std;

struct Address {
    string street;
    string city;
    int postalCode;
};

class Hospital {
public:
    string name;
    Address location;

    Hospital(string n, Address a) : name(n), location(a) {}

    void display() const {
        cout << "Hospital: " << name << endl;
        cout << "Street: " << location.street << endl;
        cout << "City: " << location.city << endl;
        cout << "Postal Code: " << location.postalCode << endl;
    }
};

int main() {
    Address address = {"Main Boulevard", "Lahore", 54000};
    Hospital hospital("City Care Hospital", address);

    hospital.display();

    return 0;
}
