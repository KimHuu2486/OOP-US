#pragma once

#include <iostream>
#include <algorithm>
#include <math.h>

class Polynomial {
private:
    int m_degree;
    double* m_coef;
public:
    Polynomial();
    Polynomial(const int& degree, const double* coef);
    Polynomial(const Polynomial& src);
    ~Polynomial();
public:
    int degree();
    void setDegree(const int& degree);
    double coefficient(const int& degree);
    void setCoefficient(const int& degree, const double& newCoef);
public:
    Polynomial operator+(const Polynomial& poly) const;
    Polynomial operator-(const Polynomial& poly) const;
    Polynomial operator*(const Polynomial& poly) const;

    Polynomial& operator=(Polynomial poly);
public:
    bool operator<(const Polynomial& poly) const;
    bool operator>(const Polynomial& poly) const;
    bool operator==(const Polynomial& poly) const;
    bool operator>=(const Polynomial& poly) const;
    bool operator<=(const Polynomial& poly) const; 
    bool operator!=(const Polynomial& poly) const;
public:
    Polynomial operator!() const;
    Polynomial operator~() const;
public:
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& src);
    friend std::istream& operator>>(std::istream& in, Polynomial& src);
};