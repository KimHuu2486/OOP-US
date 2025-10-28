#pragma once

#include <iostream>

class Monomial {
private:
    double coef;
    int exp;
public:
    Monomial();
    Monomial(const double& c, const int& e);
    Monomial(const Monomial& src);
    ~Monomial();
public:
    Monomial operator+(const Monomial& other) const;
    Monomial operator*(const Monomial& other) const;
public:
    bool operator<(const Monomial& other) const;
    bool operator>(const Monomial& other) const;
    bool operator<=(const Monomial& other) const;
    bool operator>=(const Monomial& other) const;
    bool operator==(const Monomial& other) const;
    bool operator!=(const Monomial& other) const;
public:
    Monomial& operator=(const Monomial& other);
    Monomial& operator+=(const Monomial& other);
    Monomial& operator*=(const Monomial& other);
public:
    Monomial& operator++();       
    Monomial operator++(int);      
    Monomial& operator--();
    Monomial operator--(int);
    Monomial operator!() const;
public:
    friend std::ostream& operator<<(std::ostream& out, const Monomial& m);
    friend std::istream& operator>>(std::istream& in, Monomial& m);
};

