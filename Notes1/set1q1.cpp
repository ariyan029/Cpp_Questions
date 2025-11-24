//you need to design a class that models complex numbersand supports 
//addition of two complex numbers using parameterized constructors.

#include <iostream>
using namespace std;

class Complex {
    int a, b;
public:
    Complex(int x, int y) {
        a = x;
        b = y;
    }

    Complex add(Complex c) {
        return Complex(a + c.a, b + c.b);
    }

    void display() {
        cout << a << " + " << b << "i" << endl;
    }
};

int main() {
    int x1, y1, x2, y2;

    cout << "Enter real and imaginary part of first number: ";
    cin >> x1 >> y1;

    cout << "Enter real and imaginary part of second number: ";
    cin >> x2 >> y2;

    Complex c1(x1, y1);
    Complex c2(x2, y2);

    Complex sum = c1.add(c2);

    cout << "Sum = ";
    sum.display();

    return 0;
}

