#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;


class Student {
private:
    string name;
    string number;

public:
    Student();

    Student(string, string);

    Student(const Student &);

    string getName();

    string getNumber();

    bool lessThan(Student &);

    void print();
};


#endif
