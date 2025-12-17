#pragma once
#include "Employee.h"
#include "Officer.h"
#include "Worker.h"
#include <vector>
#include <iostream>

class Company
{
private:
    std::vector<Employee *> employees;

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

            Employee *emp = nullptr;
            if (type == 1)
            {
                emp = new Officer();
            }
            else if (type == 2)
            {
                emp = new Worker();
            }
            else
            {
                std::cout << "Invalid type. Skipping employee.\n";
                --i;
                continue;
            }

            std::cin >> *emp;
            employees.push_back(emp);
        }
    }

    double calTotalSalary()
    {
        double total = 0.0;
        for (const auto &emp : employees)
        {
            total += emp->calculateSalary() + emp->calculateBonus();
        }
        return total;
    }

    ~Company()
    {
        for (auto &emp : employees)
        {
            delete emp;
        }
        employees.clear();
    }
};