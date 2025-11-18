#pragma once

#include "Vehicle.h"

class MotorBike: public Vehicle {
public:
    MotorBike(float fuel = 0, float goods = 0) 
        : Vehicle(fuel, goods) {}

    float calcFuelUsed(float km) const override{
        float base = 2.0f * (km / 100.0f);

        float extra = 0.1f * m_goods / 10.0f * (km / 100.0f);

        return base + extra;
    }
};