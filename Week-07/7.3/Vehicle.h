#pragma once

class Vehicle {
protected:
    float m_fuel;
    float m_goods;
public:
    Vehicle(float fuel = 0.0f, float good = 0.0f) 
        : m_fuel(fuel), m_goods(good) {}
    
    void addGoods(float weight) {
        m_goods += weight;
    }

    void removeGoods(float weight) {
        m_goods -= weight;
    }

    void addFuel(float fuel) {
        m_fuel += fuel;
    }

    float getFuel() const {
        return m_fuel;
    }

    virtual float calcFuelUsed(float km) const = 0;

    bool run(float km) {
        float used = calcFuelUsed(km);
        if (used > m_fuel) return false;
        m_fuel -= used;
        return true;
    }

    virtual ~Vehicle() {}
};