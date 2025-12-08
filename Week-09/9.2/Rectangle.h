#pragma once

#include "Figure.h"
#include "Point.h"

class Rectangle : public Figure {
protected:
    Point m_topLeft;
    Point m_bottomRight;
public:
    Rectangle(const Point& topLeft, const Point& bottomRight)
        : m_topLeft(topLeft), m_bottomRight(bottomRight) {
        if (!Point::isTopLeftBottomRight(topLeft, bottomRight)) {
            m_topLeft = Point(0.0, 1.0);
            m_bottomRight = Point(1.0, 0.0);  
        }
    }
    ~Rectangle() override = default;
    void print() override {
        std::cout << "Rectangle corners: " << m_topLeft << ", "
                  << m_bottomRight << std::endl;
    }
};