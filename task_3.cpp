
#include <iostream>
using namespace std;

class Rectangle {
public:
    double length;
    double width;

    double area() const {
        return length * width;
    }
};

void compare(Rectangle a, Rectangle b) {
    double areaA = a.area();
    double areaB = b.area();

    if (areaA > areaB) {
        cout << "First rectangle has the larger area." << endl;
    } else if (areaB > areaA) {
        cout << "Second rectangle has the larger area." << endl;
    } else {
        cout << "Both rectangles have the same area." << endl;
    }
}

int main() {
    Rectangle first;
    first.length = 8;
    first.width = 5;

    Rectangle second;
    second.length = 6;
    second.width = 4;

    compare(first, second);

    return 0;
}
