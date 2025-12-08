#pragma once
#include "Animal.h"

class Horse : public Animal {
public:
    Horse(const std::string& species = "Horse", double speed = 60.0) : Animal(species, speed) {}
};