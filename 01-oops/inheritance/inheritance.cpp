// Inheritance allows a class (Child class) to acquire data and methods from another class (Parent class).

#include <iostream>
using namespace std;

class Car
{
protected:
    int speed;
    string model;
    string brand;
    bool isEngineOn;

public:
    // Constructor
    Car(string model, string brand)
    {
        this->model = model;
        this->brand = brand;
        speed = 0;
        isEngineOn = false;
    }

    // Common methods for all cars
    void startEngine()
    {
        isEngineOn = true;
        cout << "Car engine started" << endl;
    }

    void stopEngine()
    {
        if (!isEngineOn)
        {
            cout << "Engine is already off." << endl;
            return;
        }

        isEngineOn = false;
        cout << "Car engine stopped" << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << "Cannot accelerate. Engine is not on." << endl;
            return;
        }

        speed += 20;
        cout << "Car accelerated to " << speed << " km/h" << endl;
    }

    void brake()
    {
        if (!isEngineOn)
        {
            cout << "Cannot brake. Engine is not on." << endl;
            return;
        }

        speed -= 20;
        if (speed < 0)
        {
            speed = 0;
        }
        cout << "Car slowed down to " << speed << " km/h" << endl;
    }
};

class ManualCar : public Car
{
private:
    int currentGear;

public:
    ManualCar(string model, string brand) : Car(model, brand)
    {
        currentGear = 0;
    }

    void shiftGear(int gear)
    {
        if (gear < 0 || gear > 5)
        {
            cout << "Invalid gear. Please select a gear between 0 and 5." << endl;
            return;
        }

        currentGear = gear;
        cout << "Gear shifted to " << currentGear << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string model, string brand) : Car(model, brand)
    {
        batteryLevel = 100; // Battery level starts at 100%
    }

    void chargeBattery()
    {
        batteryLevel = 100;
        cout << "Battery fully charged" << endl;
    }
};

int main()
{
    ManualCar *manualCar = new ManualCar("Model S", "Tesla");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->shiftGear(2);
    manualCar->accelerate();
    manualCar->brake();
    manualCar->stopEngine();

    ElectricCar *electricCar = new ElectricCar("Model 3", "Tesla");
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->chargeBattery();
    electricCar->brake();
    electricCar->stopEngine();

    return 0;
}