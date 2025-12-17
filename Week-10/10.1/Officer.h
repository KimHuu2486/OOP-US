#pragma once
#include "Employee.h"
#include <sstream>
#include <vector>

class Officer : public Employee
{
private:
    double baseSalary;
    int vacationDays;

public:
    Officer() : Employee(), baseSalary(0.0), vacationDays(0) {}

    Officer(const std::string &name, int year, int base, int vacation = 0)
        : Employee(name, year), baseSalary(base), vacationDays(vacation) {}

    double calculateSalary() const override
    {
        return baseSalary - (vacationDays * 10.0);
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

        if (tokens.size() < 4)
            throw std::invalid_argument("Officer: Thieu thong tin.");

        int n = tokens.size();
        this->year = std::stoi(tokens[n - 3]);
        this->baseSalary = std::stod(tokens[n - 2]);
        this->vacationDays = std::stoi(tokens[n - 1]);

        this->name = "";
        for (int i = 0; i < n - 3; ++i)
        {
            this->name += tokens[i];
            if (i != n - 4)
                this->name += " ";
        }
    }
};