/////////////////////////////////////////////////////////////////////
// Name:Joel Deleon
// Date: 10/14/26
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: This program calculates the person's Body Mass Index (BMI) of
// multiple patients based on their weight and height.
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;


double meters(double cm) {
    return cm / 100.0; 
}

double calculateBMI(double weight, double height) {
    double BMI = weight / (height * height);
    return BMI;
}

int main() {
    string patientsname = " ";
    double weight = 0;
    double height = 0;
    double BMI = 0;
    int totalPatients = 0;
    int patientsprocessed = 0;
    bool weightValid = false; 
    cout << "How many patients do you want to process today?" << endl;
    cin >> totalPatients;
        cin.ignore();
    


    for (int i = 0; i < totalPatients; i++) {
        weightValid = false;
        cout << "\nPlease enter the patient's name #" << patientsprocessed + 1 << ":" << endl;
        getline(cin, patientsname);

        while (!weightValid) {
            cout << "Enter weight in kg for " << patientsname << ": ";
            cin >> weight;

            if (cin.fail() || weight <= 0) {
                cout << "Invalid input. Weight must be a positive number." << endl;
                if (weight <= 0) {
                    cout << "Program terminated due to invalid weight input." << endl;
                    return 1;
                }
                cin.clear();
            } else {
                weightValid = true;
            }
        }

        cout << "Enter height in cm for " << patientsname << ": ";
        cin >> height;
        cin.ignore();

        BMI = calculateBMI(weight, meters(height));
        if (BMI >= 0) {
            cout << patientsname << "'s BMI is: " << BMI << endl;

            cout << "The BMI classification is: ";
            if (BMI < 18.5) {
                cout << "Underweight" << endl;
            } else if (BMI < 25.0) {
                cout << "Normal weight" << endl;
            } else if (BMI < 30.0) {
                cout << "Overweight" << endl;
            } else {
                cout << "Obesity" << endl;
            }
        }

        patientsprocessed++;
    }

    cout << "\nThank you for using our system. ";
    return 0;
}