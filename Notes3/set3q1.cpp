//binary and unary operator overloading

#include <iostream>
using namespace std;

class MyInt {
private:
    int value;

public:
    // --- constructors ---
    MyInt(int v = 0) : value(v) {}           // default / single-arg constructor

    // --- utility ---
    void show() const { cout << value; }

    // --- binary operator: addition (a + b) ---
    friend MyInt operator+(const MyInt &a, const MyInt &b) {
        return MyInt(a.value + b.value);
    }

    // --- binary operator: subtraction (a - b) ---
    friend MyInt operator-(const MyInt &a, const MyInt &b) {
        return MyInt(a.value - b.value);
    }

    // --- unary operator: negation (-a) ---
    MyInt operator-() const {
        return MyInt(-value);
    }

    // --- unary operator: prefix ++ (++a) ---
    MyInt& operator++() {
        ++value;            // increment value
        return *this;       // return by reference
    }

    // --- unary operator: postfix ++ (a++) ---
    MyInt operator++(int) {
        MyInt temp = *this; // copy current state
        value++;            // increment original
        return temp;        // return old state
    }

    // --- compound assignment (just to show another binary-style member overload) ---
    MyInt& operator+=(const MyInt &other) {
        value += other.value;
        return *this;
    }
};

int main() {
    cout << "Demonstrating binary and unary operator overloading\n\n";

    MyInt a(5), b(3);

    cout << "a = "; a.show(); cout << "\n";
    cout << "b = "; b.show(); cout << "\n\n";

    // Binary +
    MyInt c = a + b;         // calls friend operator+
    cout << "c = a + b = ";
    c.show(); cout << "  (5 + 3)\n";

    // Binary -
    MyInt d = a - b;         // calls friend operator-
    cout << "d = a - b = ";
    d.show(); cout << "  (5 - 3)\n\n";

    // Unary negation
    MyInt e = -a;            // calls operator-()
    cout << "e = -a = ";
    e.show(); cout << "  (-5)\n\n";

    // Prefix ++
    cout << "Before prefix ++a: a = "; a.show(); cout << "\n";
    MyInt &pref = ++a;       // calls operator++()
    cout << "After prefix ++a: a = "; a.show(); cout << "  (incremented)\n";
    cout << "Return of ++a (reference) = "; pref.show(); cout << "\n\n";

    // Postfix ++
    cout << "Before postfix b++: b = "; b.show(); cout << "\n";
    MyInt old = b++;         // calls operator++(int)
    cout << "Value returned by b++ (old b) = ";
    old.show(); cout << "\n";
    cout << "Value of b after b++ = "; b.show(); cout << "  (incremented)\n\n";

    // Compound assignment +=
    a += MyInt(10);          // calls operator+=
    cout << "After a += 10, a = "; a.show(); cout << "\n";

    cout << "\nDone.\n";
    return 0;
}
