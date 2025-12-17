#pragma once
#include "Employee.h"
#include "Officer.h"
#include "Worker.h"
#include <vector>
#include <iostream>
#include <memory>

class Company
{
private:
    std::vector<std::unique_ptr<Employee>> employees;

public:
    void input()
    {
        std::cout << "Enter number of employees: ";
        int n;
        std::cin >> n;
        std::cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            std::cout << "Enter employee type (1 for Officer, 2 for Worker): ";
            int type;
            std::cin >> type;
            std::cin.ignore();

            std::unique_ptr<Employee> emp;
            if (type == 1)
            {
                emp = std::make_unique<Officer>();
            }
            else if (type == 2)
            {
                emp = std::make_unique<Worker>();
            }
            else
            {
                std::cout << "Invalid type. Skipping employee.\n";
                --i;
                continue;
            }

            std::cin >> *emp;
            employees.push_back(std::move(emp));
        }
    }

    double calTotalSalary() const
    {
        double total = 0.0;
        for (const auto &emp : employees)
        {
            total += emp->calculateSalary() + emp->calculateBonus();
        }
        return total;
    }
};