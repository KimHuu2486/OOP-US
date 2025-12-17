#pragma once
#include <string>
#include <iostream>

class Land
{
protected:
    std::string code;
    double basePrice;

public:
    Land(const std::string &code = "", double basePrice = 0.0)
        : code(code), basePrice(basePrice) {}

    virtual ~Land() {}

    virtual double area() const = 0;

    virtual double calculatePrice() const
    {
        return area() * basePrice;
    }

    virtual void input()
    {
        std::cout << "Enter land code: ";
        std::cin >> code;
        std::cout << "Enter base price: ";
        std::cin >> basePrice;
    }

    friend std::istream &operator>>(std::istream &in, Land &land)
    {
        land.input();
        return in;
    }
};