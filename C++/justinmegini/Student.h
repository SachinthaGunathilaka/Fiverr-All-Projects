#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Student {
private:

    string firstName;
    string lastName;
    string socialSecurityNumber;
    double gradeArray[4];
    double avgExamGrade;

public:
//    int static studentNumber;
    static int studentNumber;


    Student() {}

    Student(string fname, string lname, string ssn);

    void calculateAverageGrade();

    // Setters for each attributes
    void setFirstName(string firstName);

    void setLastName(string lastName);

    void setSocialSecurityNumber(string ssn);

    void setGrades(double mark1, double mark2, double mark3, double mark4);

    // Getters for each attribute
    string getFirstName();

    string getLastName();

    string getSSN();

    double getAvgExamGrade();

//    int getNumberOfStudents();

    double *getGrades();;

    void displayDetails();

};

#endif // STUDENT_H
