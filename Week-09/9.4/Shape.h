#pragma once

class Shape {
public:
    virtual void draw() const = 0; 
    virtual ~Shape() = default;    
};