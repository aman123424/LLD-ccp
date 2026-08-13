// Dynamic Polymorphism -> Happens in different classes with same function name but different implementation. It is achieved through method overriding.
// Generally between parent and child class. The parent class function is declared as virtual and the child class function overrides it. The function to be called is determined at runtime based on the object type.
// Everything is same in both functions, only the logic is different. The function signature is same in both parent and child class (name, input and return type all are same). The function to be called is determined at runtime based on the object type.

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

    virtual void accelerate() {}

    virtual void brake() {}
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

    void accelerate() override
    {
        if (!isEngineOn)
        {
            cout << "Cannot accelerate. Engine is not on." << endl;
            return;
        }

        speed += 20;
        cout << "Manual car accelerated to " << speed << " km/h" << endl;
    }

    void brake() override
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
        cout << "Manual car slowed down to " << speed << " km/h" << endl;
    }
};

class ElectricCar : public Car
{
public:
    ElectricCar(string model, string brand) : Car(model, brand) {}

    void accelerate() override
    {
        if (!isEngineOn)
        {
            cout << "Cannot accelerate. Engine is not on." << endl;
            return;
        }

        speed += 10;
        cout << "Electric car accelerated to " << speed << " km/h" << endl;
    }

    void brake() override
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
        cout << "Electric car slowed down to " << speed << " km/h" << endl;
    }
};

int main()
{
    Car *car1 = new ManualCar("Model S", "Tesla");
    Car *car2 = new ElectricCar("Leaf", "Nissan");

    car1->startEngine();
    car1->accelerate();
    car1->brake();
    car1->stopEngine();

    cout << endl;

    car2->startEngine();
    car2->accelerate();
    car2->brake();
    car2->stopEngine();

    delete car1;
    delete car2;

    return 0;
}