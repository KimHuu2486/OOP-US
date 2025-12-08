#pragma once

#include "Point.h"

class Figure {
public:
    Figure() = default;
    virtual void print() = 0;
    virtual ~Figure() = default;
};