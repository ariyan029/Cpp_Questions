/*
consider a book reantal Management System ,which stores the details of books and customers, who rent books from it, develop a class "Book" and calculate the volume of two books using paramererized constructor
*/

#include <iostream>
using namespace std;

class Book {
private:
    string title;
    float length, width, height;   // dimensions
    string customerName;           // customer who rented the book

public:
    // Parameterized constructor
    Book(string t, float l, float w, float h, string cust)
    {
        title = t;
        length = l;
        width = w;
        height = h;
        customerName = cust;
    }

    // Calculate volume
    float volume() const {
        return length * width * height;
    }

    // Display details
    void display() const {
        cout << "Book Title: " << title << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Volume: " << volume() << " cubic units" << endl;
    }
};

int main() {

    cout << "--- Book Rental Management System ---\n";

    // Creating 2 books with customer details
    Book b1("Mathematics", 10.0, 8.0, 2.0, "Rahul");
    Book b2("English", 12.0, 9.0, 3.0, "Ariyan");

    cout << "\nDetails of Book 1:\n";
    b1.display();

    cout << "\nDetails of Book 2:\n";
    b2.display();

    return 0;
}
