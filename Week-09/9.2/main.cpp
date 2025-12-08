#include "Figure.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>

void printShapeInfo(std::vector<Figure*>& shapes) {
    for (Figure* shape : shapes) {
        shape->print();
    }
}

int main() {
    std::vector<Figure*> shapes;
    Triangle triangle(Point(0, 3), Point(1, 2), Point(3, 1));
    Rectangle rectangle(Point(2, 0), Point(0, 3));
    Circle circle(Point(1, 1), 5.0);

    shapes.push_back(&triangle);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    printShapeInfo(shapes);

    return 0;
}