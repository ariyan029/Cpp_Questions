/*
write a c++ program of a bank account deposit system account holder name , current ammount , amound deposit and amound withdrawn using constructor

*/
#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    float balance;

public:
    // Constructor to set name and current amount
    BankAccount(string n, float currentAmount) {
        name = n;
        balance = currentAmount;
    }

    // Deposit function
    void deposit(float amount) {
        balance += amount;
        cout << "Amount Deposited: " << amount << endl;
    }

    // Withdraw function
    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
        } else {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        }
    }

    void display() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc("Ariyan", 5000);

    acc.display();
    acc.deposit(1200);
    acc.withdraw(800);

    acc.display();
    return 0;
}

