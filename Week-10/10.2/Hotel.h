#pragma once
#include "Room.h"
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include <vector>
#include <iostream>

class Hotel
{
private:
    std::vector<Room *> rentedRooms;

public:
    void input()
    {
        int n;
        std::cout << "Enter number of rooms to rent: ";
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int roomType;
            std::cout << "Enter room type (1 for A, 2 for B, 3 for C): ";
            std::cin >> roomType;
            Room *room = nullptr;
            switch (roomType)
            {
            case 1:
                room = new RoomA();
                break;
            case 2:
                room = new RoomB();
                break;
            case 3:
                room = new RoomC();
                break;
            default:
                std::cout << "Invalid room type!" << std::endl;
                --i; // retry this iteration
                continue;
            }
            std::cin >> *room;
            rentedRooms.push_back(room);
        }
    }

    double calTotalRentPrice()
    {
        double total = 0.0;
        for (const auto &room : rentedRooms)
        {
            total += room->calRentPrice();
        }
        return total;
    }

    ~Hotel()
    {
        for (auto &room : rentedRooms)
        {
            delete room;
        }
    }
};