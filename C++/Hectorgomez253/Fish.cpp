#include "Fish.h"

Fish::Fish(string name, string color, double baseAdoptionFee, string waterType) : WaterPet(name, color, baseAdoptionFee,
                                                                                           waterType) {

    setType();
}


void Fish::setType() {
    this->type = "Fish";
}


void Fish::action() const {
    if (this->mood == "content") {
        cout << "Swish swish." << endl;
        cout << "Your fish " << this->getName() << " is casually swimming." << endl;
    } else if (this->mood == "hungry") {
        cout << "SWISH SWISH SWISH!!" << endl;
        cout << this->getName() << " is swimming to the top of the tank looking for food!" << endl;
    } else if (this->mood == "sick") {
        cout << this->getName() << " is hiding behind a rock and doesn't feel well." << endl;
        cout << "Time to call the vet!" << endl;
    }
}

void Fish::printInfo() const {

    WaterPet::printInfo();
    cout << "Action: ";
    this->action();
};
