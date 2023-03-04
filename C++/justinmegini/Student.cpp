#include"Student.h"

using namespace std;

// Initialize studentNumber to 0 (Static member)
int Student::studentNumber = 0;

// Constructor
Student::Student(string fname, string lname, string ssn) {
    firstName = fname;
    lastName = lname;
    socialSecurityNumber = ssn;
    Student::studentNumber += 1;
}

// Method to calculate average grade for a student
void Student::calculateAverageGrade() {
    double total = 0;
    for (auto mark: gradeArray)
        total += mark;

    avgExamGrade = total / 4.0;
}

// Setters for each attributes
void Student::setFirstName(string fname) {
    firstName = fname;
}

void Student::setLastName(string lname) {
    lastName = lname;
}

void Student::setSocialSecurityNumber(string ssn) {
    socialSecurityNumber = ssn;
}

void Student::setGrades(double mark1, double mark2, double mark3, double mark4) {
    gradeArray[0] = mark1;
    gradeArray[1] = mark2;
    gradeArray[2] = mark3;
    gradeArray[3] = mark4;
}

// Getters for each attribute
string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getSSN() {
    return socialSecurityNumber;
}

double Student::getAvgExamGrade() {
    return avgExamGrade;
}


double *Student::getGrades() {
    return gradeArray;
}

//A function for display details of a student
void Student::displayDetails() {
    cout << left << setw(15)<< firstName << setw(15) << lastName << setw(10);
    for (int i = 0; i < 4; ++i) {
        cout << setw(6) << gradeArray[i];
    }

    cout << avgExamGrade << endl;

}




