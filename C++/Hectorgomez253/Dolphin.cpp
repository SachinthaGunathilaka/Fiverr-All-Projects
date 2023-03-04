#include "Dolphin.h"

Dolphin::Dolphin(string name, string color, double baseAdoptionFee, string waterType) : WaterPet(name, color,
                                                                                                 baseAdoptionFee,
                                                                                                 waterType) {

    setType();
}


void Dolphin::setType() {
    this->type = "Dolphin";
}


void Dolphin::action() const {
    if (this->mood == "content") {
        cout << this->getName() << " is resting quietly in the water" << endl;
    } else if (this->mood == "hungry") {
        cout << this->getName() << " is swimming to the top of the water looking for food!" << endl;
    } else if (this->mood == "sick") {
        cout << this->getName() << " is not eating well" << endl;
        cout << "Time to call the vet!" << endl;
    }
}

void Dolphin::printInfo() const {

    WaterPet::printInfo();
    cout << "Action: ";
    this->action();
};
