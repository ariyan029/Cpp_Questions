// menu driven cpp for a) krishnamurti number b) armstrong number 
#include <iostream>
#include <cmath>
using namespace std;

// Function to find factorial of a digit
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to check Krishnamurthy number
bool isKrishnamurthy(int n) {
    int temp = n, sum = 0;

    while(temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    return (sum == n);
}

// Function to check Armstrong number
bool isArmstrong(int n) {
    int temp = n, sum = 0, digits = 0;

    // Count digits
    while(temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while(temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return (sum == n);
}

int main() {
    int num, choice;

    while(true) {

        cout << "\n----- MENU -----\n";
        cout << "1. Check Krishnamurthy Number\n";
        cout << "2. Check Armstrong Number\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 3) {
            cout << "Exiting program...\n";
            break;
        }

        cout << "Enter a number: ";
        cin >> num;

        switch(choice) {

            case 1:
                if(isKrishnamurthy(num))
                    cout << num << " is a Krishnamurthy Number\n";
                else
                    cout << num << " is NOT a Krishnamurthy Number\n";
                break;

            case 2:
                if(isArmstrong(num))
                    cout << num << " is an Armstrong Number\n";
                else
                    cout << num << " is NOT an Armstrong Number\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
