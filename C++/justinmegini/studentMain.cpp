#include<iostream>
#include "ClassRoom.h"

int main() {
    // Create a ClassRoom Object
    ClassRoom classRoom("CSC134");
    // Read students from students.txt file
    classRoom.readData("students.txt");
    // Sort Students by average (In ascending order)
    classRoom.sortByAverage();
    // Display list of students sorted by average
    cout << "\nSTUDENTS SORTED BY AVERAGE" << endl;
    classRoom.displaySummary();

    // Sort Students by last name
    classRoom.sortByLastName();
    // Display list of students sorted by last name
    cout << "\nSTUDENTS SORTED BY LAST NAME" << endl;
    classRoom.displaySummary();

    // Display average of all the students and number of students
    cout << "\nAverage grade of all students : " << classRoom.getAverage() << endl;
    cout << "Number of students : " << classRoom.getCount() << endl;

    return 0;
}
