#pragma once

#include "Room.h"

class RoomB : public Room
{
public:
    RoomB(int days = 0) : Room(200.0, days) {}

    void input() override
    {
        std::cout << "Enter number of days rented for Room B: ";
        std::cin >> cntDays;
    }

    double calRentPrice() override
    {
        if (cntDays < 10)
        {
            return basePrice * cntDays;
        }
        else
        {
            return basePrice * 9 + (basePrice * 0.9) * (cntDays - 9);
        }
    }

    ~RoomB() override {}
};
