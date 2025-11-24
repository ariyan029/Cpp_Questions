/*
consider a car rental MANAGEMENT SYSTEM which store the details of
 various brands of cars rented by its customers.Develop a class "car" 
 wherin you will accept user input for id brand and price of three cars 
 and display the car details using array of objects
*/


#include <iostream>
using namespace std;

class Car {
private:
    int id;
    string brand;
    float price;

public:
    // Function to accept user input
    void input() {
        cout << "Enter Car ID: ";
        cin >> id;
        cout << "Enter Car Brand: ";
        cin >> brand;
        cout << "Enter Car Price: ";
        cin >> price;
    }

    // Function to display car details
    void display() const {
        cout << "ID: " << id 
             << ", Brand: " << brand 
             << ", Price: " << price << endl;
    }
};

int main() {
    Car c[3];   // Array of objects

    // Input details for 3 cars
    cout << "Enter details of 3 cars:\n";
    for(int i = 0; i < 3; i++) {
        cout << "\nCar " << i + 1 << ":\n";
        c[i].input();
    }

    // Display car details
    cout << "\n--- Car Details ---\n";
    for(int i = 0; i < 3; i++) {
        c[i].display();
    }

    return 0;
}
