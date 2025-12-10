#include <iostream>
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include "Room.h"
#include <vector>

void inputRentedRoom(std::vector<Room*>& rooms) {
    int choice, days;
    double fee;
    while (true) {
        std::cout << "Select room type to rent:\n";
        std::cout << "1. Room A\n";
        std::cout << "2. Room B\n";
        std::cout << "3. Room C\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 3) {
            std::cout << "Enter number of days to rent: ";
            std::cin >> days;

            switch (choice) {
                case 1:
                    std::cout << "Enter additional fee for Room A: ";
                    std::cin >> fee;
                    rooms.push_back(new RoomA(days, fee));
                    break;
                case 2:
                    rooms.push_back(new RoomB(days));
                    break;
                case 3:
                    rooms.push_back(new RoomC(days));
                    break;
            }
        }
        else break;
    }
}

double calculateTotalCost(const std::vector<Room*>& rooms) {
    double total = 0.0;
    for (const auto& room : rooms) {
        total += room->calculateCost();
    }
    return total;
}

int main() {
    std::vector<Room*> rooms;

    inputRentedRoom(rooms);

    double totalCost = calculateTotalCost(rooms);
    std::cout << "Total Rental Cost: " << totalCost << std::endl;

    for (auto& room : rooms) {
        delete room;
    }

    return 0;
}