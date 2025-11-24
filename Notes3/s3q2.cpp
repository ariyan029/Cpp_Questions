/*
consider a human resource management system, which stores the salary details of the employees working in the company "ABC" DEVELOP A CLASS"Employee" wherein you will accept user input for salary and allowance of three employee and display the total salaries of these employees using array of objects
*/

#include <iostream>
using namespace std;

class Employee {
private:
    float salary;
    float allowance;

public:
    // Function to take input
    void input() {
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Allowance: ";
        cin >> allowance;
    }

    // Function to return total salary
    float totalSalary() const {
        return salary + allowance;
    }
};

int main() {
    cout << "Human Resource Management System - Company ABC\n\n";

    Employee emp[3];   // Array of objects

    // Input for 3 employees
    for(int i = 0; i < 3; i++) {
        cout << "Enter details of Employee " << i + 1 << ":\n";
        emp[i].input();
        cout << endl;
    }

    // Display total salaries
    cout << "--- Total Salaries of Employees ---\n";
    for(int i = 0; i < 3; i++) {
        cout << "Employee " << i + 1 << ": " 
             << emp[i].totalSalary() << endl;
    }

    return 0;
}
