#include <iostream>
#include "Hotel.h"

int main()
{
    Hotel hotel;
    hotel.input();
    double totalRent = hotel.calTotalRentPrice();
    std::cout << "Total rent price for all rooms: " << totalRent << std::endl;

    return 0;
}