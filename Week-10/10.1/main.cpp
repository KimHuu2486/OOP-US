#include "Company.h"
#include <iostream>


int main() {
    Company company;
    company.input();
    float totalSalary = company.calTotalSalary();
    std::cout << "Total Salary Expense: " << totalSalary << std::endl;

    return 0;
}