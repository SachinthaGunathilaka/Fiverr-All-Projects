
#include "Location.h"

const string Location::NONE = "Empty";

string Location::getId() {
    return id;
}

string Location::getProduct() {
    return product;
}

int Location::getQuantity() {
    return quantity;
}

Location::Location(char character, int number) {
    this->id = string(1, character) + to_string(number);
    this->quantity = 0;
    this->product = NONE;
}


/**
 * isEmpty function
 *
 * @return true if quantity is 0
 */
bool Location::isEmpty() {
    return quantity == 0;
}

/**
 * isAvailable function
 *
 * @return true if product is NONE
 */
bool Location::isAvailable() {
    return product.compare(NONE) == 0;
}

void Location::print() {
    cout << "Id : " << id << ",  Product : "  << product << ",  Quantity : " << quantity << endl;
}

//void Location::setProductName(int name) {
//    product = name;
//}