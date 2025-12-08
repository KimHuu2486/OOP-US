#pragma once

#include "Animal.h"

class Antelope : public Animal {
public:
    Antelope(const std::string& species = "Antelope", double speed = 80.0) : Animal(species, speed) {}
};