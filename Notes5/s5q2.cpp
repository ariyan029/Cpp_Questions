/*
Consider a Student Management system , which stores the results of the students of an institute. develop a class "Student" wherein you wil accept user input for roll number and marks of three subjectsof a student and display the total marks and grade of the students(Total marks>=80 grade A, Total marks 70-79: grade B, Total marks 60 - 69 grade C. total marks 50-59 grade D , Total marks < 50 Fail)

*/

#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    float m1, m2, m3;

public:
    // Accept user input
    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }

    // Calculate total
    float totalMarks() const {
        return m1 + m2 + m3;
    }

    // Display result + grade
    void display() const {
        float total = totalMarks();
        cout << "\nRoll Number: " << roll << endl;
        cout << "Total Marks: " << total << endl;

        cout << "Grade: ";
        if (total >= 80)
            cout << "A";
        else if (total >= 70)
            cout << "B";
        else if (total >= 60)
            cout << "C";
        else if (total >= 50)
            cout << "D";
        else
            cout << "Fail";

        cout << endl;
    }
};

int main() {
    Student s1;

    cout << "--- Student Management System ---\n";
    s1.input();
    s1.display();

    return 0;
}
