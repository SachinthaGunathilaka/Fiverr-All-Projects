#ifndef DOG_H
#define DOG_H

#include "DomesticLandPet.h"

class Dog : public DomesticLandPet {
private:

public:
    Dog(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee);

    virtual void setType();

    virtual void action() const;

    virtual void printInfo() const;



};


#endif //DOG_H
