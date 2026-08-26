// In the below example, the shape is the parent interface for square, rectangle, cube but as we can see here, area is being forcefully implemented for cube and volume is implemented for square and rectangle forcefully, so here Integration Segregation Principle is violated here.

#include <iostream>

using namespace std;

class Shape
{
public:
    int length;
    int breadth;

    Shape(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    virtual int area() = 0;

    virtual int volume() = 0;
};

class Square : public Shape
{
public:
    Square(int length) : Shape(length, length)
    {
        this->length = length;
    }

    int area() override
    {
        return length * length;
    }

    int volume() override
    {
        throw logic_error("Volume cannot be calculated for a sqaure");
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int length, int breadth) : Shape(length, breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    int area() override
    {
        return length * breadth;
    }

    int volume() override
    {
        throw logic_error("Volume cannot be calculated for a rectangle");
    }
};

class Cube : public Shape
{
public:
    Cube(int side) : Shape(length, breadth)
    {
        this->length = side;
    }

    int area() override
    {
        throw logic_error("Area cannot be calculated for a cube");
    }

    int volume() override
    {
        return length * length * length;
    }
};

int main()
{
    Shape *square = new Square(4);
    Shape *rectangle = new Rectangle(4, 3);
    Shape *cube = new Cube(4);

    try
    {
        cout << square->area() << endl;
        square->volume();
    }
    catch (const logic_error &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << rectangle->area() << endl;
        rectangle->volume();
    }
    catch (const logic_error &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << cube->volume() << endl;
        cube->area();
    }
    catch (const logic_error &e)
    {
        cout << e.what() << endl;
    }
}