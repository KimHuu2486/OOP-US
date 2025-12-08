#pragma once

#include "Animal.h"

class Cheetah : public Animal {
public:
    Cheetah(const std::string& species = "Cheetah", double speed = 100.0) : Animal(species, speed) {}
};