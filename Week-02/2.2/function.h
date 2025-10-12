#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Monomial {
private:
    string coef, expo;
    bool isNumber(string s);
    string trimZeros(string x);
public:
    void input();
    void output();
    float getCoef();
    void setCoef(string newCoef);
    float getExpo();
    void setExpo(string newExpo);
    float evaluate(float base);
    Monomial derive();
    Monomial mul(Monomial seccondMono);
};


#endif 