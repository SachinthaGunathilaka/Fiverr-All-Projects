#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    string name;
    int capacity;
    int computers;
    bool whiteboard;

public:
    Room(string, int, int, bool);

    Room(const Room &);

    string getName();

    int getCapacity();

    int getComputers();

    bool hasWhiteBoard();

    bool meetsCriteria(int= 0, int= 0, bool = false);

    bool lessThan(Room &r);

    void print();


};


#endif
