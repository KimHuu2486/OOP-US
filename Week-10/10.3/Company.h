#pragma once
#include "Land.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include <vector>
#include <iostream>
#include <memory>

class Company
{
private:
    std::vector<std::unique_ptr<Land>> lands;

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

            std::unique_ptr<Land> land;
            if (choice == 1)
            {
                land = std::make_unique<Rectangle>();
            }
            else if (choice == 2)
            {
                land = std::make_unique<Trapezoid>();
            }
            else
            {
                std::cout << "Invalid choice. Skipping this land." << std::endl;
                i--;
                continue;
            }
            std::cin >> *land;
            lands.push_back(std::move(land));
        }
    }

    double calculateTotalPrice() const
    {
        double total = 0.0;
        for (const auto &land : lands)
        {
            total += land->calculatePrice();
        }
        return total;
    }

    double calculateTotalArea() const
    {
        double totalArea = 0.0;
        for (const auto &land : lands)
        {
            totalArea += land->area();
        }
        return totalArea;
    }
};