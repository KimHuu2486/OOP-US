#pragma once
#include "Matrix.h"

class Cinema {
protected:
    Matrix<double> m_seats;
    Matrix<bool> m_booked;
    int m_rows;
    int m_cols;
public:
    Cinema(): m_seats(), m_booked(), m_rows(0), m_cols(0) {};
    Cinema(const int& r, const int& c);
    Cinema(const Cinema& other);
    virtual ~Cinema() = default;
public:
    void setCentralPrices(const double& price);
    void setPrices();
    bool isEmpty(const int& r, const int& c);
    double priceAtSeat(const int& r, const int& c);
    bool book(const int& r, const int& c);
    double revenue();
};