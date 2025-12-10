#pragma once

#include "Room.h"

class RoomB : public Room {
private:
    const double basePrice = 200.0;
public:
    RoomB(int days = 0) : Room(days) {}

    double calculateCost() const override {
        int days = getCntDays();
        if (days < 10) {
            return basePrice * days;
        } else {
            return basePrice * 9 + (basePrice * 0.9) * (days - 9);
        }
    }

    ~RoomB() override {}
};
