#pragma once

#include "Animal.h"

class Dog : public Animal {
public:
    Dog(const std::string& species = "Dog", double speed = 60.0) : Animal(species, speed) {}
};