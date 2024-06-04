#include <iostream>
#include <string>

using namespace std;

struct Car {
    int length;
    int clearance;
    int engineVolume;
    int enginePower;
    int wheelDiameter;
    string color;
    string transmissionType;
};

void setCarValues(Car& car, int length, int clearance, int engineVolume, int enginePower, int wheelDiameter, string color, string transmissionType) {
    car.length = length;
    car.clearance = clearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

void printCarValues(Car car) {
    cout << "Length: " << car.length << " mm" << endl;
    cout << "Clearance: " << car.clearance << " mm" << endl;
    cout << "Engine Volume: " << car.engineVolume << " liters" << endl;
    cout << "Engine Power: " << car.enginePower << " horsepower" << endl;
    cout << "Wheel Diameter: " << car.wheelDiameter << " inches" << endl;
    cout << "Color: " << car.color << endl;
    cout << "Transmission Type: " << car.transmissionType << endl;
}

Car searchCarByColor(Car cars[], int n, string color) {
    for (int i = 0; i < n; i++) {
        if (cars[i].color == color) {
            return cars[i];
        }
    }
    Car emptyCar;
    return emptyCar;
}

int main() {
    Car myCar;
    setCarValues(myCar, 4500, 150, 2.0, 150, 17, "black", "automatic");

    cout << "Car Information:" << endl;
    printCarValues(myCar);

    Car cars[] = {
        {4500, 150, 2.0, 150, 17, "black", "automatic"},
        {4200, 120, 1.8, 120, 16, "white", "manual"},
        {4700, 180, 3.0, 200, 18, "red", "automatic"}
    };
    int n = sizeof(cars) / sizeof(cars[0]);

    Car foundCar = searchCarByColor(cars, n, "black");
    cout << "Found Car:" << endl;
    printCarValues(foundCar);

    return 0;
}