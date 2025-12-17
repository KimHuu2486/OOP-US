#pragma once
#include "Room.h"

class RoomC : public Room
{
public:
    RoomC(int days = 0) : Room(100.0, days) {}

    void input() override
    {
        std::cout << "Enter number of days rented for Room C: ";
        std::cin >> cntDays;
    }

    double calRentPrice() override
    {
        return basePrice * cntDays;
    }

    ~RoomC() override {}
};
