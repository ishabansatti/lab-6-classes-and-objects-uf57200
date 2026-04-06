
#include <iostream>
using namespace std;

class Sensor {
public:
    static int totalSensors;
    int id;

    Sensor() {
        totalSensors++;
        id = totalSensors;
    }

    void display() const {
        cout << "Sensor ID: " << id << endl;
    }
};

int Sensor::totalSensors = 0;

int main() {
    Sensor s1;
    Sensor s2;
    Sensor s3;
    Sensor s4;

    s1.display();
    s2.display();
    s3.display();
    s4.display();

    cout << "Total Sensors: " << Sensor::totalSensors << endl;

    return 0;
}
