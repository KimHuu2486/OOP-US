#pragma once

#include "Animal.h"

class Human : public Animal {
public:
    Human(const std::string& species = "Human", double speed = 30.0) : Animal(species, speed) {}
};