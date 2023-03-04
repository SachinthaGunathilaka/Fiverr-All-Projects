#include "Cat.h"

Cat::Cat(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee) : DomesticLandPet(name,
                                                                                                                color,
                                                                                                                baseAdoptionFee,
                                                                                                                licenceFee,
                                                                                                                vetFee) {

    setType();

}

void Cat::setType() {
    this->type = "Cat";
}

void Cat::action() const {
    if (this->mood == "content") {
        cout << "Purr, purr." << endl;
        cout << "Your cat " << this->getName() << " is cuddling in your lap. " << endl;
    } else if (this->mood == "hungry") {
        cout << "MEOW. MEOW." << endl;
        cout << "Your cat " << this->getName() << " is hungry for some water and fish." << endl;
    } else if (this->mood == "sick") {
        cout << this->getName() << " is quiet and hiding and doesn't feel well." << endl;
        cout << "Time to go to the vet!!" << endl;
    } else if (this->mood == "playful") {
        cout << this->getName() << " is playing with a toy mouse. Meow" << endl;
    } else if (this->mood == "naughty") {
        cout << "Scratch. Scratch. " << this->getName() << " is scratching the curtains." << endl;
        cout << "Time to buy another scratching post or trim nails!" << endl;
    }


}

void Cat::printInfo() const {

    VirtualPet::printInfo();
    cout << "Action: ";
    this->action();
};
