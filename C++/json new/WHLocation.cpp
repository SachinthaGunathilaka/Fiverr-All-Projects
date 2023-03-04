#include "WHLocation.h"

WHLocation::WHLocation() : Location(code, nextId) {
}


int WHLocation::getCapacity() {
    return capacity;
}

bool WHLocation::add(string name, int quantity) {

    if(!isAvailable() || quantity > capacity){
        return false;
    }
    product = name;
    this->quantity = quantity;
    return true;


}

bool WHLocation::remove(int quantity) {
    if (quantity > this->quantity)
        return false;

    this->quantity -= quantity;
    if (this->quantity == 0)
        this->product = Location::NONE;
    return true;
}
