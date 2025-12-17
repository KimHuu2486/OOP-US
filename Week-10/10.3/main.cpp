#include <iostream>
#include "Company.h"

int main()
{
    Company company;
    company.input();

    std::cout << "Total Area of Lands: " << company.calculateTotalArea() << std::endl;
    std::cout << "Total Price of Lands: " << company.calculateTotalPrice() << std::endl;

    return 0;
}