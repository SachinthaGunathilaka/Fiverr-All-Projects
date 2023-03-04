//
// Created by sachi on 10/7/2021.
//

#include "Subscriber.h"

Subscriber::Subscriber(const string name, const string creditcard) {
    this->name = name;
    this->creditcard = creditcard;
}

bool Subscriber::matches(const string &name) {
    if(this->name == name)
        return true;
    return false;
}

const string &Subscriber::getName() const {
    return name;
}

void Subscriber::print() {
    cout << name << ", " << creditcard << endl;
}
