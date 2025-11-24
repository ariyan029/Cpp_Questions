//car rental company multilevel inheritence problem 
// 2.0 answer 
#include <iostream>
using namespace std;

// Base class for Car Company
class Company {
 protected:
  string companyName;

 public:
  void inputCompany() {
    cout << "Enter Car Company Name: ";
    cin >> companyName;
  }
};

// Derived class for Car Models
class Car : public Company {
 protected:
  string model;
  float rentPerDay;

 public:
  void inputCar() {
    inputCompany();  // calling parent function
    cout << "Enter Car Model: ";
    cin >> model;
    cout << "Enter Rent Per Day: ";
    cin >> rentPerDay;
  }
};

// Derived class for Customer from Car
class Customer : public Car {
 private:
  string customerName;
  int rentDays;

 public:
  void inputCustomer() {
    inputCar();  // calling parent function
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter Number of Days Rented: ";
    cin >> rentDays;
  }

  void display() {
    cout << "\n====== RENT DETAILS ======\n";
    cout << "Company: " << companyName << endl;
    cout << "Car Model: " << model << endl;
    cout << "Rent Per Day: " << rentPerDay << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Days Rented: " << rentDays << endl;
    cout << "Total Rent Amount: " << rentPerDay * rentDays << endl;
  }
};

// Main function
int main() {
  Customer c;
  c.inputCustomer();
  c.display();
  return 0;
}