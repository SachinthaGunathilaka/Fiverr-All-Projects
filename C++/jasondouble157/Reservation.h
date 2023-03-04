#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Date.h"

using namespace std;

class Reservation {
private:
    Student *student;
    Room *room;
    Date *date;

public:
    Reservation(Student *, Room *, Date *);

    ~Reservation();

    Student *getStudent();

    Room *getRoom();

    Date *getDate();

    bool lessThan(Reservation &);

    bool overlaps(string r, Date &d);

    void print();

};


#endif
