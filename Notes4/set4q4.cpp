//develop a menu driven c++ program to check whether a number is 
//a)perfect number b)armstrong or not ..
#include <iostream>
#include <cmath>
using namespace std;

// Function to check Perfect Number
bool isPerfect(int n) {
    int sum = 0;
    for(int i = 1; i <= n/2; i++) {
        if(n % i == 0)
            sum += i;
    }
    return (sum == n);
}

// Function to check Armstrong Number
bool isArmstrong(int n) {
    int temp = n, sum = 0;
    int digits = 0;

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
    int choice, num;

    while(true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Check Perfect Number\n";
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
                if(isPerfect(num))
                    cout << num << " is a Perfect Number\n";
                else
                    cout << num << " is NOT a Perfect Number\n";
                break;

            case 2:
                if(isArmstrong(num))
                    cout << num << " is an Armstrong Number\n";
                else
                    cout << num << " is NOT an Armstrong Number\n";
                break;

            default:
                cout << "Invalid choice! Please select again.\n";
        }
    }

    return 0;
}
