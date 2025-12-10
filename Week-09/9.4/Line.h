#pragma once
#include "Point.h"
#include "Shape.h"
#include <iostream>

class Line {
private:
    Point m_p1;
    Point m_p2;
public:
    Line(const Point& p1 = Point(), const Point& p2 = Point()) : m_p1(p1), m_p2(p2) {}
    void drawLine() const {
        std::cout << "Drawing a Line" << std::endl;
    }
};

class LineShape : public Shape {
private:
    Line m_line;
public:
    LineShape(const Point& p1 = Point(), const Point& p2 = Point()) : m_line(p1, p2) {}
    void draw() const override {
        m_line.drawLine();
    }
};