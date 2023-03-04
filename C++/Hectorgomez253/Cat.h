#ifndef CAT_H
#define CAT_H
#include "DomesticLandPet.h"

class Cat: public DomesticLandPet{
public:
    Cat(string name, string color, double baseAdoptionFee, double licenceFee, double vetFee);

    virtual void setType();

    virtual void action() const;

    virtual void printInfo() const;


};


#endif //CAT_H
