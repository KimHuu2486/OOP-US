#include "Monomial.h"

Monomial::Monomial() 
    : coef(0), exp(0) 
{
}

Monomial::Monomial(const double& c, const int& e) 
    : coef(c), exp(e) 
{
}

Monomial::Monomial(const Monomial& src) 
    : coef(src.coef), exp(src.exp) 
{
}

Monomial::~Monomial() {}

Monomial Monomial::operator+(const Monomial& other) const {
    if (exp == other.exp) {
        return Monomial(coef + other.coef, exp);
    }
    return *this; // khi không cùng số mũ, trả về đơn thức ban đầu
}

Monomial Monomial::operator*(const Monomial& other) const {
    return Monomial(coef * other.coef, exp + other.exp);
}

bool Monomial::operator<(const Monomial& other) const { 
    if (exp == other.exp) {
        return coef < other.coef;
    }
    return exp < other.exp;
}

bool Monomial::operator>(const Monomial& other) const {
    if (exp == other.exp) {
        return coef > other.coef;
    }
    return exp > other.exp;
}

bool Monomial::operator<=(const Monomial& other) const {
    return !(*this > other);
}

bool Monomial::operator>=(const Monomial& other) const {
    return !(*this < other);
}

bool Monomial::operator==(const Monomial& other) const {
    return coef == other.coef && exp == other.exp;
}

bool Monomial::operator!=(const Monomial& other) const {
    return !(*this == other);
}

Monomial& Monomial::operator=(const Monomial& other) {
    if (this != &other) {
        coef = other.coef;
        exp = other.exp;
    }
    return *this;
}

Monomial& Monomial::operator+=(const Monomial& other) {
    if (exp == other.exp) {
        coef += other.coef;
    }
    return *this; // khi không cùng số mũ, không thay đổi gì
}

Monomial& Monomial::operator*=(const Monomial& other) {
    coef *= other.coef;
    exp += other.exp;
    return *this;
}

Monomial& Monomial::operator++() {
    ++exp;
    return *this;
}

Monomial Monomial::operator++(int) {
    Monomial temp = *this;
    ++exp;
    return temp;
}

Monomial& Monomial::operator--() {
    --exp;
    return *this;
}

Monomial Monomial::operator--(int) {
    Monomial temp = *this;
    --exp;
    return temp;
}

Monomial Monomial::operator!() const {
    Monomial result;
    if (exp != 0) {
        result.coef = coef * exp;
        result.exp = exp - 1;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const Monomial& m) {
    out << m.coef << "x^" << m.exp;
    return out;
}

std::istream& operator>>(std::istream& in, Monomial& m) {
    in >> m.coef >> m.exp;
    return in;
}