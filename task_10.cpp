
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double c) : celsius(c) {}

    void setCelsius(double value) {
        if (value < -273.15) {
            cout << "Invalid temperature." << endl;
            return;
        }
        celsius = value;
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32;
    }

    double getKelvin() const {
        return celsius + 273.15;
    }
};

int main() {
    Temperature temp(25);

    temp.setCelsius(-300);

    cout << "Celsius: " << temp.getCelsius() << endl;
    cout << "Fahrenheit: " << temp.getFahrenheit() << endl;
    cout << "Kelvin: " << temp.getKelvin() << endl;

    return 0;
}
