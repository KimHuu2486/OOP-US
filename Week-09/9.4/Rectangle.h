#pragma once
#include "Point.h"
#include "Shape.h"
#include <iostream>

class Rectangle {
private:
    Point m_p1;
    Point m_p2;
public:
    Rectangle(const Point& p1 = Point(), const Point& p2 = Point())
        : m_p1(p1), m_p2(p2) {}
    void drawRectangle() const {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

class RectangleShape : public Shape {
private:
    Rectangle m_rectangle;
public:
    RectangleShape(const Point& p1 = Point(), const Point& p2 = Point())
        : m_rectangle(p1, p2) {}    
    void draw() const override {
        m_rectangle.drawRectangle();
    }
};