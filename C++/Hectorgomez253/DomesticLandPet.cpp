#include "DomesticLandPet.h"

DomesticLandPet::DomesticLandPet(string name, string color, double baseAdoptionFee, double licenceFee, double vetFees)
        : VirtualPet(name, color, baseAdoptionFee >= 0 ? baseAdoptionFee : 25) {

    this->licenceFee = licenceFee >= 0 ? licenceFee : 10;
    this->vetFees = vetFees >= 0 ? vetFees : 80;

}

void DomesticLandPet::setLicenceFee(double licenceFee) {
    this->licenceFee = licenceFee >= 0 ? licenceFee : 10;
}

void DomesticLandPet::setVetFees(double vetFee) {
    this->vetFees = vetFee >= 0 ? vetFee : 80;
}

double DomesticLandPet::getLicenceFee() const {
    return licenceFee;
}

double DomesticLandPet::getVetFees() const {
    return vetFees;
}

void DomesticLandPet::setMood(string md) {
    if (md == "content" || md == "hungry" || md == "sick" || md == "playful" || md == "naughty") {
        mood = md;
    } else {
        mood = "content";
    }
}

double DomesticLandPet::calcAdoptionCost() const {
    return VirtualPet::calcAdoptionCost() + this->getVetFees() + this->getLicenceFee();
}

void DomesticLandPet::changeMood() {
    int num;

    switch (num) {
        case 1:
            mood = "content";
            break;
        case 2:
            mood = "hungry";
            break;
        case 3:
            mood = "sick";

        case 4:
            mood = "playful";

        case 5:
            mood = "naughty";
    }
}


