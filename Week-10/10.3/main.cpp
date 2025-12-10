#include <iostream>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Land.h"
#include <vector>

void inputListLand(std::vector<Land*>& lands) {
    while (true) {
        int choice;
        std::cout << "Select land type to input:\n";
        std::cout << "1. Rectangle\n";
        std::cout << "2. Trapezoid\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            Rectangle* rect = new Rectangle();
            std::cin >> *rect;
            lands.push_back(rect);
        }
        else if (choice == 2) {
            Trapezoid* trap = new Trapezoid();
            std::cin >> *trap;
            lands.push_back(trap);
        }
        else {
            break;
        }
    }
}

double calculateTotalLandPrice(const std::vector<Land*>& lands) {
    double total = 0.0;
    for (const auto& land : lands) {
        total += land->calculatePrice();
    }
    return total;
}

double calculateTotalArea(const std::vector<Land*>& lands) {
    double totalArea = 0.0;
    for (const auto& land : lands) {
        totalArea += land->area();
    }
    return totalArea;
}

int main () {
    std::vector<Land*> lands;

    inputListLand(lands);

    double totalPrice = calculateTotalLandPrice(lands);
    double totalArea = calculateTotalArea(lands);

    std::cout << "Total Land Price: " << totalPrice << std::endl;
    std::cout << "Total Land Area: " << totalArea << std::endl;

    for (auto& land : lands) {
        delete land;
    }

    return 0;
}