#pragma once
#include "Room.h"

class RoomA : public Room {
private:
    const double basePrice = 300.0;
    double fee;
public:
    RoomA(int days = 0, double fee = 0.0) : Room(days), fee(fee) {}

    double calculateCost() const override {
        int days = getCntDays();
        if (days < 10) {
            return basePrice * days + fee;
        } else {
            return basePrice * 9 + (basePrice * 0.9) * (days - 9) + fee;
        }
    }
    ~RoomA() override {}
};