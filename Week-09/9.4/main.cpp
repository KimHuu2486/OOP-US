#include <iostream>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include <vector>

void drawAllShapes(const std::vector<Shape*>& shapes) {
    for (const Shape* shape : shapes) {
        shape->draw();
    }
}

int main() {
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    Point p3(5.0, 6.0);

    LineShape line(p1, p2);
    RectangleShape rectangle(p1, p3);

    std::vector<Shape*> shapes = { &line, &rectangle };
    drawAllShapes(shapes);

    return 0;
}