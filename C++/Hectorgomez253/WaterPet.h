#ifndef WATERPET_H
#define WATERPET_H

#include "VirtualPet.h"
#include <iostream>


using namespace std;

class WaterPet : public VirtualPet {
private:
    string waterType;

public:
    WaterPet(string name, string color, double baseAdoptionFee, string water_type);

    string getWaterType();

    virtual void printInfo() const;
};


#endif //WATERPET_H
