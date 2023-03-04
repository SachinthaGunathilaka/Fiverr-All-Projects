#ifndef RABIT_H
#define RABIT_H

#include "DomesticLandPet.h"

class Rabbit : public DomesticLandPet {

public:
    Rabbit(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee);

    virtual void setType();

    virtual void action() const;

    virtual void printInfo() const;
};


#endif //RABIT_H
