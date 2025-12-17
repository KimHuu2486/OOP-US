#pragma once
#include "Room.h"

class RoomA : public Room
{
private:
    double fee;

public:
    RoomA(int days = 0, double fee = 0.0) : Room(300.0, days), fee(fee) {}

    void input() override
    {
        std::cout << "Enter number of days rented for Room A: ";
        std::cin >> cntDays;
        std::cout << "Enter additional fee for Room A: ";
        std::cin >> fee;
    }

    double calRentPrice() override
    {
        if (cntDays < 10)
        {
            return basePrice * cntDays + fee;
        }
        else
        {
            return basePrice * 9 + (basePrice * 0.9) * (cntDays - 9) + fee;
        }
    }
    
    ~RoomA() override {}
};