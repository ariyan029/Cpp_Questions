/*
A company evaluates its employees based on their job type Developer -> evaluated on number of projects compiled. Manager--> ealuated on numbers of teams handled The company wants a flexible evaluation system using virtual functions,allowing different evaluation criteria for each employee type

*/
#include <iostream>
using namespace std;

// Base Class
class Employee {
protected:
    string name;

public:
    Employee(string n) {
        name = n;
    }

    // Virtual function to allow flexible evaluation
    virtual void evaluate() {
        cout << "General Employee Evaluation\n";
    }
};

// Derived Class: Developer
class Developer : public Employee {
private:
    int projectsCompleted;

public:
    Developer(string n, int p) : Employee(n) {
        projectsCompleted = p;
    }

    void evaluate() override {
        cout << "\nDeveloper: " << name << endl;
        cout << "Projects Completed: " << projectsCompleted << endl;
    }
};

// Derived Class: Manager
class Manager : public Employee {
private:
    int teamsHandled;

public:
    Manager(string n, int t) : Employee(n) {
        teamsHandled = t;
    }

    void evaluate() override {
        cout << "\nManager: " << name << endl;
        cout << "Teams Handled: " << teamsHandled << endl;
    }
};

int main() {
    // Creating objects
    Developer d("Ariyan", 8);
    Manager m("Rahul", 3);

    // Base class pointer
    Employee *ptr;

    ptr = &d;  
    ptr->evaluate();   // calls Developer version

    ptr = &m;
    ptr->evaluate();   // calls Manager version

    return 0;
}
