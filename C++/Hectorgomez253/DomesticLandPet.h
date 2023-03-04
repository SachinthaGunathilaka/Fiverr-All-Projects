#ifndef DOMESTICLANDPET_H
#define DOMESTICLANDPET_H
#include "VirtualPet.h"
#include <iostream>


using namespace std;
class DomesticLandPet : public VirtualPet{
private:
    double licenceFee;
    double vetFees;

public:
    DomesticLandPet(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee);

    void setLicenceFee(double licenceFee);

    void setVetFees(double vetFees);

    double getLicenceFee() const;

    double getVetFees() const;

    virtual void setMood(string);

    virtual double calcAdoptionCost() const;

    virtual void changeMood();

};


#endif //DOMESTICLANDPET_H
