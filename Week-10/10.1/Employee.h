#pragma once

#include <string>
#include <iostream>

const int CURRENT_YEAR = 2025;

class Employee {
protected:
    std::string name;
    int get_in_year;
public:
    Employee() : name(""), get_in_year(0) {}

    Employee(const std::string& name, int year) : name(name), get_in_year(year) {}

    std::string getName() const {
        return name;
    }

    virtual double calculateSalary() const = 0; 

    double calculateBonus() const {
        return 100 + (CURRENT_YEAR - get_in_year) * 10;
    }

    virtual void input(std::istream& in) = 0;

    friend std::istream& operator>>(std::istream& in, Employee& emp) {
        emp.input(in);
        return in;
    }

    virtual ~Employee() = default;
};