#include "StoreLocation.h"

//StoreLocation::nextId = 0;
StoreLocation::StoreLocation() : Location(code, nextId) {
//    StoreLocation::nextId += 1;
}

void StoreLocation::setProduct(string name) {
    this->product = name;
}

int StoreLocation::getFreeSpace() {
    return capacity - getQuantity();
}

int StoreLocation::getCapacity() {
    return capacity;
}

bool StoreLocation::add(string name, int quantity) {
    if(name.compare(product) != 0){
        return false;
    }

    if(getFreeSpace() < quantity){
        return false;
    }

    product = name;
    this->quantity += quantity;
    return true;


}

bool StoreLocation::remove(int quantity) {
    if(quantity > this->quantity)
        return false;

    this->quantity -= quantity;
    return true;
}