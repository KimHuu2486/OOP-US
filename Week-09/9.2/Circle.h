#pragma once

#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
protected:
    Point m_center;
    double m_radius;
public:
    Circle(const Point& center, double radius)
        : m_center(center), m_radius(radius) {
        if (radius <= 0.0) {
            m_center = Point(0.0, 0.0);
            m_radius = 1.0;
        }
    }
    ~Circle() override = default;
    void print() override {
        std::cout << "Circle center: " << m_center
                  << ", radius: " << m_radius << std::endl;
    }
};