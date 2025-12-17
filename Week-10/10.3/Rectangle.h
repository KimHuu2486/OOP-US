#pragma once
#include "Land.h"

class Rectangle : public Land {
private:
    double height;
    double width;
public:
    Rectangle(const std::string& code = "", double basePrice = 0.0,
              double height = 0.0, double width = 0.0)
        : Land(code, basePrice), height(height), width(width) {}

    double area() const override {
        return height * width;
    }

    void input() override {
        Land::input();
        std::cout << "Enter height: ";
        std::cin >> height;
        std::cout << "Enter width: ";
        std::cin >> width;
    }
};