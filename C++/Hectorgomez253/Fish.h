#ifndef FISH_H
#define FISH_H

#include "WaterPet.h"

class Fish : public WaterPet {

public:
    Fish(string name, string color, double baseAdoptionFee, string waterType);

    virtual void setType();

    virtual void action() const;

    virtual void printInfo() const;



};


#endif //FISH_H
