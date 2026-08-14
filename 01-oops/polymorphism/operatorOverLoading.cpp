// Operator overloading means giving a new meaning to an existing operator.
// With operator overloading, we can give make operators work for user-defined class structures.
// It is an example of compile-time polymorphism.

// The following operators cannot be overloaded
// 1. sizeof operator
// 2. typeid operator
// 3. Scope resolution operator (::)
// 4. Class member access operators (. and .*)
// 5. Ternary / conditional operator (?:)

#include <iostream>
using namespace std;

class Complex {
    public:
        int real;
        int imaginery;

    Complex(int real, int imaginery) {
        this->real = real;
        this->imaginery = imaginery;
    }

    void display() {
        cout << real << " + " << imaginery << "i" << endl;
    }

    // Overloading + operator to add two Complex numbers
    Complex operator+(Complex const &c2) {
        Complex result(0, 0);
        result.real = this->real + c2.real;
        result.imaginery = this->imaginery + c2.imaginery;
        return result;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(5, 6);

    Complex c3 = c1 + c2; // Using overloaded + operator
    c3.display();

    return 0;
}