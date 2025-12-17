#pragma once
#include "Employee.h"
#include <sstream>
#include <vector>

class Worker : public Employee
{
private:
    int products;

public:
    Worker() : Employee(), products(0) {}

    Worker(const std::string &name, int year, int products)
        : Employee(name, year), products(products) {}

    double calculateSalary() const override
    {
        return products * 10.0;
    }

    void input(std::istream &in) override
    {
        std::string info;
        std::getline(in, info);

        if (info.empty())
            return;

        std::stringstream ss(info);
        std::vector<std::string> tokens;
        std::string temp;
        while (ss >> temp)
            tokens.push_back(temp);

        if (tokens.size() < 3)
            throw std::invalid_argument("Worker: Thieu thong tin.");

        int n = tokens.size();
        this->year = std::stoi(tokens[n - 2]);
        this->products = std::stoi(tokens[n - 1]);

        this->name = "";
        for (int i = 0; i < n - 2; ++i)
        {
            this->name += tokens[i];
            if (i != n - 3)
                this->name += " ";
        }
    }
};