#include <vector>
#include "Library.h"

Library::Library() {
    students = new Student *[max_capacity];
    reservations = new Reservation *[max_capacity];
    student_index = 0;
    room_index = 0;
    reservation_index = 0;
}

Library::~Library() {
    delete[] students;
    delete[] reservations;

}

bool Library::addStudent(const string &name, const string &number) {
    if (student_index >= max_capacity)
        return false;
    Student *student = new Student(name, number);
    int i;
    for (i = 0; i < student_index; ++i) {
        if (student->lessThan(*students[i]))
            break;
    }

    Student *temp = students[i];
    students[i] = student;

    for (int j = student_index - 1; j > i; --j) {
        students[j + 1] = students[j];
    }
    students[i + 1] = temp;
    student_index++;
    return true;

}

bool Library::addRoom(const string &name, int capacity, int computers, bool whiteboard) {
    if (room_index >= max_capacity)
        return false;

    Room *room = new Room(name, capacity, computers, whiteboard);
    int i;
    for (i = 0; i < room_index; ++i) {
        if (room->lessThan(*rooms[i]))
            break;
    }

    Room *temp = rooms[i];
    rooms[i] = room;

    for (int j = room_index - 1; j > i; --j) {
        rooms[j + 1] = rooms[j];
    }
    rooms[i + 1] = temp;
    room_index++;
    return true;
}

bool Library::getStudent(const string &name, Student **student) {
    for (int i = 0; i < student_index; ++i) {
        if (students[i]->getName() == name) {
            *student = students[i];
            return true;
        }
    }
    return false;
}

bool Library::getRoom(const string &roomName, Room **room) {
    for (int i = 0; i < room_index; ++i) {
        if (rooms[i]->getName() == roomName) {
            *room = rooms[i];
            return true;
        }
    }
    return false;
}

bool Library::isFree(const string &room, Date &date) {
    bool isExist = false;
    for (int i = 0; i < room_index; ++i) {
        if (rooms[i]->getName() == room)
            isExist = true;
    }

    if (!isExist)
        return false;

    bool isFree = true;
    for (int i = 0; i < reservation_index; ++i) {
        if (reservations[i]->overlaps(room, date)) {
            isFree = false;

        }
    }
    return isFree;
}


bool Library::makeReservation(const string &student, const string &room, Date &date) {
    if (reservation_index >= max_capacity)
        return false;

    int std_index = -1;

    for (int i = 0; i < student_index; ++i) {
        if (students[i]->getName() == student) {
            std_index = i;
            break;

        }
    }
    int r_index = -1;
    for (int i = 0; i < room_index; ++i) {
        if (rooms[i]->getName() == room) {
            r_index = i;
            break;

        }

    }
    if (std_index == -1)
        return false;

    if (!isFree(room, date)) {
        return false;
    }

    Reservation *reservation = new Reservation(students[std_index], rooms[r_index], &date);

    int i;
    for (i = 0; i < reservation_index; ++i) {
        if (reservation->lessThan(*reservations[i]))
            break;
    }

    Reservation *temp = reservations[i];
    reservations[i] = reservation;

    for (int j = room_index - 1; j > i; --j) {
        reservations[j + 1] = reservations[j];
    }
    reservations[i + 1] = temp;
    reservation_index++;
    return true;


}

void Library::printReservations() {
    for (int i = 0; i < reservation_index; ++i) {
        reservations[i]->print();
    }
}

void Library::update(Date &date) {
    int new_index = 0;
    Reservation **new_reservations = new Reservation *[max_capacity];

    for (int i = 0; i < reservation_index; ++i) {
        bool onDate = reservations[i]->getDate()->getYear() == date.getYear() &&
                      reservations[i]->getDate()->getMonth() == date.getMonth() &&
                      reservations[i]->getDate()->getDay() == date.getDay();

        if (!reservations[i]->getDate()->lessThan(date) && !onDate) {
            new_reservations[new_index] = reservations[i];
            new_index++;
        }

    }

    reservations = new_reservations;
    reservation_index = new_index;

}






