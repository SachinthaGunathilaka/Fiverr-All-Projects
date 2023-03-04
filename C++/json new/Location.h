#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "string.h"

using namespace std;

class Location {
public:
    string getId();
    string getProduct();
    int getQuantity();
    Location(char character, int number);
    bool isEmpty();
    bool isAvailable();
    void print();

    virtual int getCapacity() = 0;
    virtual bool add(string name, int quantity) = 0;
    virtual bool remove(int quantity) = 0;

protected:
    int quantity;
    string product;
    static const string NONE;


private:
    string id;




};


#endif
