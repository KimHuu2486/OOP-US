#pragma once
#include "Figure.h"
#include "Point.h"

class Triangle: public Figure {
protected:
    Point m_a;
    Point m_b;
    Point m_c;
public:
    Triangle(const Point& a, const Point& b, const Point& c)
        : m_a(a), m_b(b), m_c(c) {
        if (Point::isStraightLine(a, b, c)) {
            m_a = Point(0.0, 0.0);
            m_b = Point(1.0, 0.0);
            m_c = Point(0.0, 1.0);
        }
    }
    ~Triangle() override = default;
    void print() override {
        std::cout << "Triangle vertices: " << m_a << ", "
                  << m_b << ", " << m_c << std::endl;
    }
};