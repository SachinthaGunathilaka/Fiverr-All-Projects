#ifndef LIBRARY_H
#define LIBRARY_H

#include "Reservation.h"
#include "Student.h"
#include "Room.h"

class Library {
private:
    Student **students;
    Room *rooms[10];
    Reservation **reservations;

    int student_index;
    int room_index;
    int reservation_index;

    static const int max_capacity = 10;

public:
    Library();

    ~Library();

    bool addStudent(const string &name, const string &number);

    bool addRoom(const string &name, int = 1, int = 0, bool = false);

    bool getStudent(const string &name, Student **student);

    bool getRoom(const string &roomName, Room **room);

    bool isFree(const string &room, Date &);

    bool makeReservation(const string &student, const string &room, Date &date);

    void printReservations();

    void update(Date &date);

};


#endif
