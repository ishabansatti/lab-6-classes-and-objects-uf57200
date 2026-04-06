
#include <iostream>
using namespace std;

class Box {
public:
    double l;
    double w;
    double h;

    Box() : l(1), w(1), h(1) {}
    Box(double side) : l(side), w(side), h(side) {}
    Box(double a, double b, double c) : l(a), w(b), h(c) {}

    double volume() const {
        return l * w * h;
    }

    void display() const {
        cout << "Dimensions: " << l << " x " << w << " x " << h << endl;
    }
};

Box largerBox(Box a, Box b) {
    if (a.volume() >= b.volume()) {
        return a;
    }
    return b;
}

int main() {
    Box first(2, 3, 4);
    Box second(3, 3, 3);

    Box result = largerBox(first, second);
    result.display();

    return 0;
}
