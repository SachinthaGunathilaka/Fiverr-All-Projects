// Import libraries
#include <iostream>
#include <iomanip>

using namespace std;

// Main function
int main() {
    // Define array to store patient count for each age group and initialize it to 0
    int patients[5] = {0};

    // Define array to store age ranges
    int ranges[6] = {0, 20, 40, 70, 90, 110};

    // Get input for age
    int age;
    cout << "Enter Age: ";
    cin >> age;

    // Define variables to hold highest and lowest age
    int highest_age = -1;
    int lowest_age = 110;

    // Define variables to hold total patients and total patients below 70
    int total_patients = 0, patients_below_70 = 0;

    // Loop runs until user enter age greater than 109
    while (age <= 109) {

        // Increment total patients
        total_patients++;

        // If age of the current patient is less than 70 increment patients below 70
        if (age < 70) {
            patients_below_70++;
        }

        // Calculate highest age
        if (age > highest_age)
            highest_age = age;

        // Calculate lowest age
        if (age < lowest_age)
            lowest_age = age;

        // Increment number of patients in the relevant group
        for (int i = 0; i < 6; ++i) {
            if (age < ranges[i + 1]) {
                patients[i]++;
                break;
            }
        }

        // Get input for age again
        cout << "Enter Age: ";
        cin >> age;

    }


    // Calculate maximum patients in a group
    int max_count = 0;
    for (int i = 0; i < 5; ++i) {
        if (patients[i] > max_count)
            max_count = patients[i];
    }
    cout << endl << " ";

    // Display all the age groups
    for (int i = 0; i < 5; ++i) {
        string range = to_string(ranges[i]) + " - " + to_string(ranges[i + 1] - 1);
        cout << fixed << setw(9) << left << range;

    }

    cout << endl;


    // Iterate through each line
    for (int i = 0; i < max_count; ++i) {

        // Iterate through each age group
        for (int j = 0; j < 5; ++j) {

            // Display * or space
            if (patients[j] > i) {
                cout << "    " << left << "*" << "    ";
            } else {
                cout << setw(9) << "";

            }
        }

        cout << endl;
    }

    // Display statistical details
    cout << "\nTotal number of outpatients visited in a day: " << total_patients << endl;
    cout << "Total number of patients in day who are below the age of 70: " << patients_below_70 << endl;

    // Display highest and lowest age (Only if there is at least 1 patient)
    if (total_patients > 0) {
        cout << "The highest age of patients visited the hospital in a day: " << highest_age << endl;
        cout << "The lowest age of patients visited the hospital in a day: " << lowest_age << endl;
    }


    return 0;
}
