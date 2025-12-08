#pragma once

#include "Animal.h"

class Lion : public Animal {
public:
    Lion(const std::string& species = "Lion", double speed = 70.0) : Animal(species, speed) {}
};