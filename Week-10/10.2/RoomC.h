#pragma once
#include "Room.h"

class RoomC : public Room {
private:
    const double basePrice = 100.0;
public:
    RoomC(int days = 0) : Room(days) {}

    double calculateCost() const override {
        int days = getCntDays();
        return basePrice * days;
    }
    
    ~RoomC() override {}
};
