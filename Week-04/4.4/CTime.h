#pragma once

#include <ctime>

class CTime {
private:
    long long absSeconds;
public:
    CTime();
    CTime(const int& h, const int& m, const int& s);
    CTime(const CTime& other);
    CTime(const long long& totalSeconds);
    ~CTime();
public:
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    long long getTotalSeconds() const;
    void setHours(const int& h);
    void setMinutes(const int& m); 
    void setSeconds(const int& s);
    void setTotalSeconds(const long long& totalSeconds);
}