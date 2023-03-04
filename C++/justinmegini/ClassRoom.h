#ifndef CLASSROOM_H
#define CLASSROOM_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include "Student.h"

using namespace std;

class ClassRoom {
private:
    string name;
    int num_of_students;
    Student *students;

public:
    ClassRoom(string name);

    ~ClassRoom();

    void readData(string filename);

    double getAverage();

    void displaySummary();

    int getCount();

    void sortByAverage();

    void sortByLastName();

};

#endif
