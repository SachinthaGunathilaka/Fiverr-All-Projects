#include "Rabbit.h"

Rabbit::Rabbit(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee) : DomesticLandPet(
        name,
        color,
        baseAdoptionFee,
        licenceFee,
        vetFee) {

    setType();

}

void Rabbit::setType() {
    this->type = "Rabbit";
}

void Rabbit::action() const {
    if (this->mood == "content") {
        cout << this->getName() << " is sleeping in your lap. " << endl;
    } else if (this->mood == "hungry") {
        cout << this->getName() << " is chewing on its cage." << endl;
        cout << "Time to feed some foods." << endl;
    } else if (this->mood == "sick") {
        cout << this->getName() << " is hiding away and breathing faster." << endl;
        cout << "Time to go to the vet!!" << endl;
    } else if (this->mood == "playful") {
        cout << this->getName() << " is pushing and rearranging its toys" << endl;
    } else if (this->mood == "naughty") {
        cout << this->getName() << " is twitching their tail up and down quickly" << endl;
    }


}

void Rabbit::printInfo() const {

    VirtualPet::printInfo();
    cout << "Action: ";
    this->action();
};
