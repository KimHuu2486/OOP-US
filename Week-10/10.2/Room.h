#pragma once
#include <iostream>

class Room
{
protected:
    double basePrice;
    int cntDays;

public:
    Room(double base = 0, int days = 0) : basePrice(base), cntDays(days) {}

    virtual void input() = 0;

    friend std::istream &operator>>(std::istream &in, Room &room)
    {
        room.input();
        return in;
    }

    virtual double calRentPrice()
    {
        return basePrice * cntDays;
    }

    virtual ~Room() {}
};