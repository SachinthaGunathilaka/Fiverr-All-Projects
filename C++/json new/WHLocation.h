#ifndef WHLOCATION_H
#define WHLOCATION_H

#include "defs.h"
#include "Location.h"


class WHLocation: public Location{

private:
    static const char code = 'B';
    static const int capacity = WHLOC_CAPACITY;
    static const int nextId = 0;
public:
    WHLocation();
    int getCapacity();
    bool add(string name, int quantity);
    bool remove(int quantity);

};


#endif
