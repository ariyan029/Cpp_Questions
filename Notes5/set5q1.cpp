//menu driven cpp program 1. sum of digits 2.swap two numbers

#include <iostream>
using namespace std;

// Function to calculate sum of digits
int sumOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to swap two numbers
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int choice;

    while(true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Sum of digits of a number\n";
        cout << "2. Swap two numbers\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                cout << "Sum of digits = " << sumOfDigits(num) << endl;
                break;
            }

            case 2: {
                int x, y;
                cout << "Enter first number: ";
                cin >> x;
                cout << "Enter second number: ";
                cin >> y;

                cout << "\nBefore swapping: x = " << x << ", y = " << y << endl;
                swapNumbers(x, y);
                cout << "After swapping:  x = " << x << ", y = " << y << endl;
                break;
            }

            case 3:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
