#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Student {
private:
    string name;
    float lit, math;
    bool isNumber(string s);
public:
    void input();
    void output();
    string getName();
    void setName(string newName);
    float getLit();
    void setLit(float newLit);
    float getMath();
    void setMath(float newMath);
    float calculateGPA();
    string grade();
};

#endif