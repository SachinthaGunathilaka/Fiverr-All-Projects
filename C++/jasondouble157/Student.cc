
#include "Student.h"

Student::Student() {
    this->name = "";
    this->number = "";
}

Student::Student(string name, string number) {
    this->name = name;
    this->number = number;
}

Student::Student(const Student &student) {
    this->name = student.name;
    this->number = student.number;
}

string Student::getName() {
    return this->name;
}

string Student::getNumber() {
    return this->number;
}

bool Student::lessThan(Student &s) {
    if (this->number.compare(s.number) < 0) {
        return true;
    }
    return false;
}


void Student::print() {
    cout << "Name : " << name << "  Number : " << number << endl;
}
