#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "WaterPet.h"


class Dolphin : public WaterPet{

public:
    Dolphin(string name, string color, double baseAdoptionFee, string waterType);

    virtual void setType();

    virtual void action() const;

    virtual void printInfo() const;

};


#endif //DOLPHIN_H
