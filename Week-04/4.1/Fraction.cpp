#include "Fraction.h"

Fraction::Fraction()
    : _num(0),
    _den(1) 
{
}

Fraction::Fraction(const int& value)
    : _num(value),
    _den(1)
{
}

Fraction::Fraction(const int& num, const int& den)
    : Fraction()
{
    if (den != 0) {
        _num = num;
        _den = den;
    }
}

Fraction::Fraction(const Fraction& src)
    : _num(src._num),
    _den(src._den)
{
}

Fraction::~Fraction() {}

int Fraction::getNum() const {
    return _num;
}

int Fraction::getDen() const {
    return _den;
}

void Fraction::setNum(const int& newNum) {
    _num = newNum;
}
void Fraction::setDen(const int& newDen) {
    if (newDen != 0) {
        _den = newDen;
    }
}

Fraction Fraction::operator+(const Fraction& f) {
    Fraction result;
    result._num = this->_num * f._den + this->_den * f._num;
    result._den = this->_den * f._den;
    return result;
}

Fraction Fraction:: operator*(const Fraction& f) {
    Fraction result;
    result._num = this->_num * f._num;
    result._den = this->_den * f._den;
    return result;
}

bool Fraction::operator>(const Fraction& f) {
    return (this->_num * f._den) > (this->_den * f._num);
}

bool Fraction::operator<(const Fraction& f) {
    return (this->_num * f._den) < (this->_den * f._num);
}

bool Fraction::operator==(const Fraction& f) {
    return (this->_num * f._den) == (this->_den * f._num);
}
bool Fraction::operator>=(const Fraction& f) {
    return (this->_num * f._den) >= (this->_den * f._num);
} 
bool Fraction::operator<=(const Fraction& f) {
    return (this->_num * f._den) <= (this->_den * f._num);
}

bool Fraction::operator!=(const Fraction& f) {
    return (this->_num * f._den) != (this->_den * f._num);
}

Fraction& Fraction::operator=(const Fraction& f) {
    if (this != &f) {
        this->_num = f._num;
        this->_den = f._den;
    }
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& f) {
    this->_num = this->_num * f._den + this->_den * f._num;
    this->_den = this->_den * f._den;
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& f) {
    this->_num = this->_num * f._num;
    this->_den = this->_den * f._den;
    return *this;
}

Fraction& Fraction::operator++() {
    this->_num += this->_den;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    this->_num += this->_den;
    return temp;
}

Fraction::operator float() const {
    return 1.f * this->_num / this->_den;
}

Fraction::operator int() const {
    return this->_num / this->_den;
}

std::ostream& operator<<(std::ostream& out, const Fraction& src) {
    out << src._num << "/" << src._den;
    return out;
}
std::istream& operator>>(std::istream& in, Fraction& src) {
    in >> src._num >> src._den;
    while (src._den == 0) {
        std::cout << "Denominator is not valid, Please reinput!" << std::endl;
        in >> src._den;
    }
    return in; 
}