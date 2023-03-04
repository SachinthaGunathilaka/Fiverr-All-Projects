#ifndef STORELOCATION_H
#define STORELOCATION_H

#include "Location.h"
#include "defs.h"

class StoreLocation : public Location{
private:
    static const char code = 'A';
    static const int capacity = SLOC_CAPACITY;
    static const int nextId = 0;

public:
    StoreLocation();
    void setProduct(string name);
    int getFreeSpace();

     int getCapacity();
      bool add(string name, int quantity);
      bool remove(int quantity);

};


#endif
