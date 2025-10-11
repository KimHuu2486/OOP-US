#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
class Monomial {
private:
    string coef, expo;
    bool isNumber(string s);
public:
    void input();
    void output();
    float getCoef();
    void setCoef(int newCoef);
    float getExpo();
    void setExpo(int newExpo);
    float evaluate(float base);
    Monomial derive();
    Monomial mul(Monomial seccondMono);
};


#endif