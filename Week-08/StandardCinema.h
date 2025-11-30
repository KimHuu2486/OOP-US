#pragma once
#include "Cinema.h"

class StandardCinema : public Cinema
{
public:
    StandardCinema(int r, int c)
        : Cinema(r, c)
    {
        setCentralPrices(10.0);
        setPrices();
    }
};