// Abstraction means hiding unnecessary details/implementation details from the user (the object interacting with the class), and only showing the important details.
// In the below example, the user of the Car class does not need to know how the engine works or how the speed is accelerated. They just need to know how to start the engine, accelerate, shift gear, brake, and stop the engine. The implementation details of these actions are hidden from the user, which is an example of abstraction in object-oriented programming.

#include <iostream>
using namespace std;

class Car
{
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    Car(string brand, string model)
    {
        this->brand = brand;
        this->model = model;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << "Engine started." << endl;
    }

    void accelerate()
    {
        if (isEngineOn)
        {
            currentSpeed += 20;
            cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }

    void shiftGear(int gear)
    {
        if (isEngineOn)
        {
            currentGear = gear;
            cout << "Gear shifted to: " << currentGear << endl;
        }
        else
        {
            cout << "Cannot shift gear. Engine is off." << endl;
        }
    }

    void brake()
    {
        if (isEngineOn)
        {
            currentSpeed -= 20;
            if (currentSpeed < 0)
                currentSpeed = 0;
            cout << "Braking. Current speed: " << currentSpeed << " km/h" << endl;
        }
        else
        {
            cout << "Cannot brake. Engine is off." << endl;
        }
    }

    void stopEngine()
    {
        if (!isEngineOn)
        {
            cout << "Engine is already off." << endl;
            return;
        }

        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "Engine stopped." << endl;
    }
};

int main()
{
    Car myCar("Toyota", "Camry");
    myCar.startEngine();
    myCar.accelerate();
    myCar.shiftGear(1);
    myCar.brake();
    myCar.stopEngine();
    return 0;
}