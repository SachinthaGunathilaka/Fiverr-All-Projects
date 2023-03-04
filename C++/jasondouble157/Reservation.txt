#include "Reservation.h"

Reservation::Reservation(Student *student, Room *room, Date *date) {
    this->student = student;
    this->room = room;
    this->date = date;
}

Reservation::~Reservation() {
    delete student;
    delete room;
    delete date;
}

Student *Reservation::getStudent() {
    return student;
}

Room *Reservation::getRoom() {
    return room;
}

Date *Reservation::getDate() {
    return date;
}

bool Reservation::overlaps(string r, Date &d) {
    if (room->getName() == r && this->date->overlaps(d)) {
        return true;
    }
    return false;
}

void Reservation::print() {
    cout << "Student => ";
    student->print();

    cout << "Date    => ";
    date->print();

    cout << "Room    => ";
    room->print();

    cout << "\n";


}

bool Reservation::lessThan(Reservation &res) {
    return date->lessThan(*res.getDate());
}


