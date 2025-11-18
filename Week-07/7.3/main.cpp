#include <iostream>
#include "MotorBike.h"
#include "Truck.h"

int main() {
    MotorBike motor(5, 20); 
    Truck truck(100, 2000); 

    motor.run(50); 
    truck.run(100);

    std::cout << "MotorBike fuel left: " << motor.getFuel() << "\n";
    std::cout << "Truck fuel left: " << truck.getFuel() << "\n";

    return 0;
}