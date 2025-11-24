/*
using the multilebel inheritance solve the question . A car company has no of cars with different models.You have to list them to the company and check the details of the customer who has taken them for rent

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
class Vehicle {
protected:
    string company;
public:
    Vehicle(string c = "QuickCars") : company(c) {}
};
class Car : public Vehicle {
protected:
    int id;
    string model;
    double rent;
    bool available;
public:
    Car(int i, string m, double r) : Vehicle(), id(i), model(m), rent(r), available(true) {}
    virtual ~Car() {}
    int getId() const { return id; }
    bool isAvailable() const { return available; }
    string getModel() const { return model; }
    double getRent() const { return rent; }
    void setAvailable(bool v) { available = v; }
    virtual void showRow() const {
        cout << left << setw(6) << id << setw(15) << model << setw(8) << rent
             << setw(10) << (available ? "Available" : "Rented") << '\n';
    }
};

class RentedCar : public Car {
    string custName, custContact;
    int days;
public:
    RentedCar(int i, string m, double r, string name, string contact, int d)
      : Car(i, m, r), custName(name), custContact(contact), days(d) { available = false; }
    void showRenter() const {
        cout << "Car ID: " << id << "\nModel: " << model << "\nCustomer: " << custName
             << "\nContact: " << custContact << "\nDays: " << days
             << "\nTotal Rent: " << rent * days << '\n';
    }
    void showRow() const override { Car::showRow(); }
};

void header() {
    cout << left << setw(6) << "ID" << setw(15) << "Model" << setw(8) << "Rent" << setw(10) << "Status" << '\n';
    cout << string(40, '-') << '\n';
}

int main() {
    vector<Car*> fleet;
    fleet.push_back(new Car(1, "Swift", 1500));
    fleet.push_back(new Car(2, "i20", 1200));
    fleet.push_back(new Car(3, "Innova", 3500));

    while (true) {
        cout << "\n1.List  2.Rent  3.Show Renter  4.Return  5.Exit\nChoice: ";
        int ch; if (!(cin >> ch)) break;
        if (ch == 5) break;

        if (ch == 1) {
            header();
            for (auto c : fleet) c->showRow();
        }
        else if (ch == 2) {
            int id; cout << "Enter Car ID to rent: "; cin >> id;
            bool found = false;
            for (size_t i = 0; i < fleet.size(); ++i) {
                if (fleet[i]->getId() == id) {
                    found = true;
                    if (!fleet[i]->isAvailable()) { cout << "Already rented.\n"; break; }
                    cin.ignore(); 
                    string name, contact; int days;
                    cout << "Customer name: "; getline(cin, name);
                    cout << "Contact: "; getline(cin, contact);
                    cout << "Days: "; cin >> days;
                    string model = fleet[i]->getModel();
                    double rent = fleet[i]->getRent();
                    delete fleet[i];
                    fleet[i] = new RentedCar(id, model, rent, name, contact, days);
                    cout << "Rented successfully.\n";
                    break;
                }
            }
            if (!found) cout << "Car not found.\n";
        }
        else if (ch == 3) {
            int id; cout << "Enter Car ID: "; cin >> id;
            bool found = false;
            for (auto c : fleet) {
                if (c->getId() == id) {
                    found = true;
                    if (c->isAvailable()) { cout << "Car is available (not rented).\n"; break; }
                    RentedCar* rc = dynamic_cast<RentedCar*>(c);
                    if (rc) rc->showRenter();
                    else cout << "No renter data.\n";
                    break;
                }
            }
            if (!found) cout << "Car not found.\n";
        }
        else if (ch == 4) {
            int id; cout << "Enter Car ID to return: "; cin >> id;
            bool found = false;
            for (size_t i = 0; i < fleet.size(); ++i) {
                if (fleet[i]->getId() == id) {
                    found = true;
                    if (fleet[i]->isAvailable()) { cout << "Car is not rented.\n"; break; }
                    // convert back to plain Car using model & rent
                    string model = fleet[i]->getModel();
                    double rent = fleet[i]->getRent();
                    delete fleet[i];
                    fleet[i] = new Car(id, model, rent);
                    cout << "Car returned.\n";
                    break;
                }
            }
            if (!found) cout << "Car not found.\n";
        }
        else cout << "Invalid choice.\n";
    }

    for (auto p : fleet) delete p;
    cout << "Bye\n";
    return 0;
}
