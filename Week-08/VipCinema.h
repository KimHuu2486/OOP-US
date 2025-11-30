#pragma once
#include "Cinema.h"
#include <string>
#include <algorithm>
#include <cctype>

class VipCinema : public Cinema
{
private:
    std::string m_day;

public:
    VipCinema(int r, int c, std::string day = "Monday")
        : Cinema(r, c), m_day(day) 
    {
        std::transform(m_day.begin(), m_day.end(), m_day.begin(),
                       [](unsigned char ch)
                       { return std::tolower(ch); });

        setCentralPrices(15.00);
        setPrices();

        if (m_day == "thursday") {
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    m_seats[i][j] *= 0.8;
                }
            }
        }
    };
};