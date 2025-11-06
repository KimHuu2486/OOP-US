#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

class init_vector {
private:
    std::vector<int> m_vec;
public:
    init_vector();
    init_vector(int N);
public:
    void initEvenOddList(const int& N);
    void initPrimeList(const int& N);
public:
    void print();
};
