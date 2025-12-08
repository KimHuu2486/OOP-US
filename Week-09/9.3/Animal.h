#pragma once
#include <string>

class Animal {
private:
    double m_speed;
    std::string m_species;
public:
    Animal(const std::string& species = "Animal", double speed = 0.0) : m_species(species), m_speed(speed) {}
    const std::string& species() const{
        return m_species;
    }
    double speed() const{
        return m_speed;
    }
    virtual ~Animal() = default;
};