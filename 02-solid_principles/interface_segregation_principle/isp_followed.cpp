//

#include <iostream>

using namespace std;

class TwoDimensionalShape
{
public:
    int length;
    int breadth;

    TwoDimensionalShape(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    virtual int area() = 0;
};

class ThreeDimensionalShape
{
public:
    int length;
    int breadth;
    int height;

    ThreeDimensionalShape(int length, int breadth, int height)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    virtual int volume() = 0;
};

class Square : public TwoDimensionalShape
{
public:
    Square(int length) : TwoDimensionalShape(length, length)
    {
        this->length = length;
    }

    int area() override
    {
        return length * length;
    }
};

class Rectangle : public TwoDimensionalShape
{
public:
    Rectangle(int length, int breadth) : TwoDimensionalShape(length, breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    int area() override
    {
        return length * breadth;
    }
};

class Cube : public ThreeDimensionalShape
{
public:
    Cube(int length) : ThreeDimensionalShape(length, length, length)
    {
        this->length = length;
    }

    int volume() override
    {
        return length * length * length;
    }
};

class Cuboid : public ThreeDimensionalShape
{
public:
    Cuboid(int lendth, int breadth, int height) : ThreeDimensionalShape(length, breadth, height)
    {
        this->length = lendth;
        this->breadth = breadth;
        this->height = height;
    }

    int volume() override
    {
        return length * breadth * height;
    }
};

int main()
{
    TwoDimensionalShape *square = new Square(4);
    TwoDimensionalShape *rect = new Rectangle(4, 3);
    ThreeDimensionalShape *cube = new Cube(5);
    ThreeDimensionalShape *cuboid = new Cuboid(4, 3, 2);

    cout << "Square area: " << square->area() << endl;
    cout << "Rectangle are: " << rect->area() << endl;
    cout << "Cube volume: " << cube->volume() << endl;
    cout << "Cuboid volume: " << cuboid->volume() << endl;
}