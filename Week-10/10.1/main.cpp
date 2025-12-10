#include "Employee.h"
#include "Officer.h"
#include "Worker.h"
#include <iostream>
#include <vector>
#include <sstream>

void inputEmployees(std::vector<Employee*>& employees) {
    int choice;
    while (true) {
        std::cout << "Enter 1 to add Officer, 2 to add Worker, 0 to finish: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "Enter name, year of joining, base salary, vacation days: ";
            Officer* officer = new Officer();
            std::cin >> *officer;
            employees.push_back(officer);
        } else if (choice == 2) {
            std::cout << "Enter name, year of joining, number of products: ";
            Worker* worker = new Worker();
            std::cin >> *worker;
            employees.push_back(worker);
        } else if (choice == 0) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

double calculateTotalSalaries(const std::vector<Employee*>& employees) {
    double total = 0.0;
    for (const auto& emp : employees) {
        total += emp->calculateSalary() + emp->calculateBonus();
    }
    return total;
}

int main() {
    std::vector<Employee*> employees;

    inputEmployees(employees);

    double totalSalaries = calculateTotalSalaries(employees);
    std::cout << "Total Salaries and Bonuses: " << totalSalaries << std::endl;

    for (auto& emp : employees) {
        delete emp;
    }

    return 0;
}