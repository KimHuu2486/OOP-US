#pragma once

class Room {
private:
    int cntDays;
public:
    Room(int days = 0) : cntDays(days) {}

    int getCntDays() const {
        return cntDays;
    }

    virtual ~Room() {}

    virtual double calculateCost() const = 0;
};