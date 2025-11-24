/*
Create a bank account with account holder name account number
 using parameterized constructors and make functions to withdraw and deposit money

*/
#include <iostream>
using namespace std;

class Bank {
private:
    string holderName;
    int accountNumber;
    float balance;

public:
    // Parameterized constructor
    Bank(string name, int accNo) {
        holderName = name;
        accountNumber = accNo;
        balance = 0;   // Initial balance set to 0
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
        }
    }

    void show() {
        cout << "\nAccount Holder: " << holderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Bank b1("Ariyan", 12345);

    b1.deposit(2000);
    b1.withdraw(500);

    b1.show();
    return 0;
}
