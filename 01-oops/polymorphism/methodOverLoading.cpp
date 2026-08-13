// Static Polymorphism (Compile time)-> Happens in the same class with same function name but different input parameters. It is achieved through method overloading.

#include <iostream>
using namespace std;

class Car
{
private:
    int speed;
    string model;
    string brand;
    bool isEngineOn;

public:
    Car(string model, string brand)
    {
        this->model = model;
        this->brand = brand;
        speed = 0;
        isEngineOn = false;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void stopEngine()
    {
        if (!isEngineOn)
        {
            cout << "Engine is already off for " << brand << " " << model << endl;
            return;
        }

        isEngineOn = false;
        speed = 0;
        cout << "Engine stopped for " << brand << " " << model << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << "Cannot accelerate. Engine is not on." << endl;
            return;
        }

        speed += 10;
        cout << "Car accelerated to " << speed << " km/h" << endl;
    }

    void accelerate(int increment)
    {
        if (!isEngineOn)
        {
            cout << "Cannot accelerate. Engine is not on." << endl;
            return;
        }

        speed += increment;
        cout << "Car accelerated to " << speed << " km/h" << endl;
    }

    void brake()
    {
        if (!isEngineOn)
        {
            cout << "Cannot brake. Engine is not on." << endl;
            return;
        }

        speed -= 10;
        if (speed < 0)
        {
            speed = 0;
        }
        cout << "Car slowed down to " << speed << " km/h" << endl;
    }
};

int main()
{
    Car myCar("Model S", "Tesla");
    myCar.startEngine();
    myCar.accelerate();
    myCar.accelerate(20);
    myCar.brake();
    myCar.stopEngine();

    return 0;
}