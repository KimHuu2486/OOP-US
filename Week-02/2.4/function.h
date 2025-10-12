#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <iostream>
using namespace std;
using sortCriteria = bool (*)(const int&, const int&);
bool acsending(const int& a, const int& b);
bool desending(const int& a, const int& b);

class Array{
private:
    int size;
    int* arr = nullptr;
public:
    void input();
    void output();
    int getSize();
    void setSize(int newSize);
    int getElement(int idx);
    void setElement(int idx, int val);
    int find(int val);
    void sort(sortCriteria cmp);
    void deleteArray();
};

#endif