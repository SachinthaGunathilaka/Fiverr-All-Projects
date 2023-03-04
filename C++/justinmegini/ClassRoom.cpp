#include "ClassRoom.h"

// Constructor
ClassRoom::ClassRoom(string name_) {
    name = name_;
    num_of_students = 0;
    students = new Student[24];
}

// Destructor
ClassRoom::~ClassRoom() {
    delete[] students;
}

// Method to read data from given file
void ClassRoom::readData(string filename) {
    string firstName, lastName, SSN;
    double m1, m2, m3, m4;

    ifstream infile(filename);

    // Read line by line
    while (infile >> firstName >> lastName >> SSN >> m1 >> m2 >> m3 >> m4) {

        // Create student object with the details in the line
        Student student(firstName, lastName, SSN);
        student.setGrades(m1, m2, m3, m4);
        student.calculateAverageGrade();

        // Add student to students Array
        students[Student::studentNumber - 1] = student;
    }
    infile.close();
}

// Method to get average of all students
double ClassRoom::getAverage() {
    double average = 0;
    for (int i = 0; i < Student::studentNumber; ++i) {
        average += students[i].getAvgExamGrade();
    }

    return average / Student::studentNumber;
}

// Method to sort Students by their average
void ClassRoom::sortByAverage() {
    int i, j;
    for (i = 0; i < Student::studentNumber - 1; i++)
        for (j = 0; j < Student::studentNumber - i - 1; j++) {
            if (students[j].getAvgExamGrade() > students[j + 1].getAvgExamGrade()){
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }

        }

}

// Method to sort Students by their last name
void ClassRoom::sortByLastName() {
    int i, j;
    for (i = 0; i < Student::studentNumber - 1; i++)

        for (j = 0; j < Student::studentNumber - i - 1; j++) {
            if (students[j].getLastName().compare(students[j+1].getLastName()) > 0){
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }

        }

}

// Method to show details of each Student
void ClassRoom::displaySummary() {
    cout << left << setw(15) << "\nFirst Name" << setw(15) << "Last Name" << setw(10);
    cout << setw(20) << "\t\t  Marks" << "Average" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < Student::studentNumber; ++i) {
        students[i].displayDetails();
    }

}

// Method to return number of students
int ClassRoom::getCount() {
    return Student::studentNumber;
}



