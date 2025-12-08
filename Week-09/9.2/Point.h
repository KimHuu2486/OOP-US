#pragma once
#include <iostream>

class Point {
private:
    double m_x;
    double m_y;
public:
    Point(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.m_x << "; " << point.m_y << ")";
        return os;
    }
public:
    static bool isStraightLine(const Point& p1, const Point& p2, const Point& p3) {
        return (p2.m_y - p1.m_y) * (p3.m_x - p2.m_x) == (p3.m_y - p2.m_y) * (p2.m_x - p1.m_x);
    }
    static bool isTopLeftBottomRight(const Point& topLeft, const Point& bottomRight) {
        return (topLeft.m_x >= bottomRight.m_x) && (topLeft.m_y <= bottomRight.m_y);
    }
};