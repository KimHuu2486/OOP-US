#pragma once

#include "Vehicle.h"

class Truck: public Vehicle {
public:
    Truck(float fuel = 0, float goods = 0) 
        : Vehicle(fuel, goods) {}

    float calcFuelUsed(float km) const override{
        float base = 20.0f * (km / 100.0f);

        float extra = 1.0f * m_goods / 1000 * (km / 100.0f);

        return base + extra;
    }
};