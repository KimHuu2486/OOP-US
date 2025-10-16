#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>

template <class T>
class Array {
private:
    T* m_arr;
    int m_size;
public:
    Array();
    Array(const int& size);
    Array(const T arr[], const int& size);
    Array(const Array& arr);
    ~Array();
    //Hàm check khai báo
    void print();
};

#include "Array.cpp"

#endif