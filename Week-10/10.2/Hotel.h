#pragma once
#include "Room.h"
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include <vector>
#include <iostream>
#include <memory>

class Hotel
{
private:
    std::vector<std::unique_ptr<Room>> rentedRooms;

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

            std::unique_ptr<Room> room;
            switch (roomType)
            {
            case 1:
                room = std::make_unique<RoomA>();
                break;
            case 2:
                room = std::make_unique<RoomB>();
                break;
            case 3:
                room = std::make_unique<RoomC>();
                break;
            default:
                std::cout << "Invalid room type!" << std::endl;
                --i;
                continue;
            }
            std::cin >> *room;
            rentedRooms.push_back(std::move(room));
        }
    }

    double calTotalRentPrice() const
    {
        double total = 0.0;
        for (const auto &room : rentedRooms)
        {
            total += room->calRentPrice();
        }
        return total;
    }
};