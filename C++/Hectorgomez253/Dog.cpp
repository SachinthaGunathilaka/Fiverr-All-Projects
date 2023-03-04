#include "Dog.h"

Dog::Dog(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee) : DomesticLandPet(name,
                                                                                                                color,
                                                                                                                baseAdoptionFee,
                                                                                                                licenceFee,
                                                                                                                vetFee) {
    setType();


}


void Dog::setType() {
    this->type = "Dog";
}


void Dog::action() const {
    if (this->mood == "content") {
        cout << "Stretch and snore." << endl;
        cout << "Your dog " << this->getName() << " is sleeping next to you." << endl;
    } else if (this->mood == "hungry") {
        cout << "RUFF RUFF!!" << endl;
        cout << this->getName() << " is hungry for some food and treats (table scraps preferred)! " << endl;
    } else if (this->mood == "sick") {
        cout << "Whine, cry, sad dog eyes." << endl;
        cout << this->getName() << " doesn't feel well" << endl;
        cout << "Time to go to the vet!!" << endl;
    } else if (this->mood == "playful") {
        cout << this->getName() << " brought you a ball. Throw it and play fetch!" << endl;
    } else if (this->mood == "naughty") {
        cout << "Chew. Chew. " << this->getName() << " chewed up a magazine." << endl;
        cout << "Time to buy more toys or go to obedience class!" << endl;
    }


}


void Dog::printInfo() const {

    VirtualPet::printInfo();
    cout << "Action: ";
    this->action();
};