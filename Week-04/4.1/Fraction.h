#pragma once

#include <iostream>

class Fraction {
private:
    int _num;
    int _den;
public:
    Fraction();
    Fraction(const int&);
    Fraction(const int&, const int&);
    Fraction(const Fraction&);
    ~Fraction();
public:
    int getNum() const;
    int getDen() const;
    void setNum(const int&);
    void setDen(const int&);
public:
    Fraction operator+(const Fraction&);
    Fraction operator*(const Fraction&);
    bool operator>(const Fraction&);
    bool operator<(const Fraction&);
    bool operator==(const Fraction&);
    bool operator>=(const Fraction&);
    bool operator<=(const Fraction&);
    bool operator!=(const Fraction&);
public:
    Fraction& operator=(const Fraction&);
    Fraction& operator+=(const Fraction&);
    Fraction& operator*=(const Fraction&);
public:
    Fraction& operator++();
    Fraction operator++(int);
public:
    operator float() const;
    operator int() const;
public:
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);
};