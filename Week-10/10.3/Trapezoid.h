#pragma once
#include "Land.h"

class Trapezoid : public Land {
private:
    double height;
    double parallel1;
    double parallel2;
public:
    Trapezoid(const std::string& code = "", double basePrice = 0.0,
              double height = 0.0, double parallel1 = 0.0, double parallel2 = 0.0)
        : Land(code, basePrice), height(height), parallel1(parallel1), parallel2(parallel2) {}  
        
    double area() const override {
        return 0.5 * (parallel1 + parallel2) * height;
    }

    double calculatePrice() const override {
        return area() * basePrice * 0.95;
    }

    void input() override {
        Land::input();
        std::cout << "Enter height: ";
        std::cin >> height;
        std::cout << "Enter length of parallel side 1: ";
        std::cin >> parallel1;
        std::cout << "Enter length of parallel side 2: ";
        std::cin >> parallel2;
    }
};