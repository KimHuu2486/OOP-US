#pragma once
#include "Land.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include <vector>
#include <iostream>

class Company
{
private:
    std::vector<Land *> lands;

public:
    void input()
    {
        int n;
        std::cout << "Enter number of lands: ";
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int choice;
            std::cout << "Enter type of land (1 for Rectangle, 2 for Trapezoid): ";
            std::cin >> choice;
            Land *land = nullptr;
            if (choice == 1)
            {
                land = new Rectangle();
            }
            else if (choice == 2)
            {
                land = new Trapezoid();
            }
            else
            {
                std::cout << "Invalid choice. Skipping this land." << std::endl;
                i--;
                continue;
            }
            std::cin >> *land;
            lands.push_back(land);
        }
    }

    double calculateTotalPrice()
    {
        double total = 0.0;
        for (const auto &land : lands)
        {
            total += land->calculatePrice();
        }
        return total;
    }

    double calculateTotalArea()
    {
        double totalArea = 0.0;
        for (const auto &land : lands)
        {
            totalArea += land->area();
        }
        return totalArea;
    }

    ~Company()
    {
        for (auto &land : lands)
        {
            delete land;
        }
    }
};