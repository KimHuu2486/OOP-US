#pragma once

#include <string>
#include <iostream>

class Employee
{
protected:
    std::string name;
    int year;

public:
    Employee() : name(""), year(0) {}

    Employee(const std::string &name, int year) : name(name), year(year) {}

    std::string getName() const
    {
        return name;
    }

    virtual double calculateSalary() const = 0;

    double calculateBonus() const
    {
        return 100 + year * 10;
    }

    virtual void input(std::istream &in) = 0;

    friend std::istream &operator>>(std::istream &in, Employee &emp)
    {
        emp.input(in);
        return in;
    }

    virtual ~Employee() = default;
};