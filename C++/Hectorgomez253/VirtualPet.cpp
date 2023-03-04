#include "VirtualPet.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

using namespace std;

VirtualPet::VirtualPet(string nme, string clr, double fee) {
    srand((unsigned int) time(NULL));
    type = "";
    setName(std::move(nme));
    setColor(clr);
    setMood("content");
    setBaseAdoptionFee(fee);
}

void VirtualPet::setName(string nm) {
    name = nm;
}

string VirtualPet::getName() const {
    return name;
}

string VirtualPet::getType() const {
    return type;
}

void VirtualPet::setColor(string clr) {
    color = clr;
}

string VirtualPet::getColor() const {
    return color;
}

string VirtualPet::getMood() const {
    return mood;
}

// NOTE: There are better ways to write this function but keep it simple like this
void VirtualPet::setMood(string md) {
    if (md == "content" || md == "hungry" || md == "sick") {
        mood = md;
    } else {
        mood = "content";
    }
}

void VirtualPet::setBaseAdoptionFee(double fee) {
    if (fee > 0) {
//double base = getBaseAdoptionFee();
        baseAdoptionFee = fee;
    } else {
        baseAdoptionFee = 25.0;
    }
}

double VirtualPet::getBaseAdoptionFee() const {
    return baseAdoptionFee;
}

double VirtualPet::calcAdoptionCost() const {
    return baseAdoptionFee;
}

// to randomly change the virtual pet's mood

void VirtualPet::changeMood() {
    int num = rand() % 3 + 1;
    switch (num) {
        case 1:
            mood = "content";
            break;
        case 2:
            mood = "hungry";
            break;
        case 3:
            mood = "sick";
    }
}

void VirtualPet::printInfo() const {
    cout << "\n\nVIRTUAL PET INFO" << endl;
    cout << "---------------------" << endl;
    cout << "Adoption Cost: " << calcAdoptionCost() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Type: " << getType() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Mood: " << getMood() << endl;
}

