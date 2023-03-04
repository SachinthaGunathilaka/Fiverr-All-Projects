#include "Room.h"

Room::Room(string name, int capacity, int computers, bool whiteboard) {
    this->name = name;
    this->capacity = capacity;
    this->computers = computers;
    this->whiteboard = whiteboard;
}

Room::Room(const Room &room) {
    this->name = room.name;
    this->capacity = room.capacity;
    this->computers = room.computers;
    this->whiteboard = room.whiteboard;
}

string Room::getName() {
    return this->name;
}

int Room::getCapacity() {
    return this->capacity;
}

int Room::getComputers() {
    return this->computers;
}

bool Room::hasWhiteBoard() {
    return whiteboard;
}

bool Room::meetsCriteria(int capacity, int computers, bool whiteboard) {
    if (this->capacity >= capacity && this->computers >= computers && (this->whiteboard || !whiteboard)) {
        return true;
    }
    return false;
}

bool Room::lessThan(Room &r) {
    if (this->name.compare(r.name) < 0) {
        return true;
    }
    return false;
}

void Room::print() {
    cout << "Name : " << name << "  Capacity : " << capacity << "  Computers : " << computers << "  Has Whiteboard : "
         << whiteboard << endl;
}


