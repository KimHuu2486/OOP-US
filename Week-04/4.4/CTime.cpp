#include "CTime.h"

CTime::CTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    absSeconds = localTime->tm_hour * 3600 + localTime->tm_min * 60 + localTime->tm_sec;
}

CTime::CTime(const int& h, const int& m, const int& s) 
    : absSeconds(h * 3600 + m * 60 + s) 
{}

CTime::CTime(const CTime& other) 
    : absSeconds(other.absSeconds) 
{}

CTime::CTime(const long long& totalSeconds) 
    : absSeconds(totalSeconds) 
{}

CTime::~CTime() {}

int CTime::getHours() const {
    return absSeconds / 3600;
}

int CTime::getMinutes() const {
    return (absSeconds % 3600) / 60;
}

int CTime::getSeconds() const {
    return absSeconds % 60;
}

long long CTime::getTotalSeconds() const {
    return absSeconds;
}

void CTime::setTotalSeconds(const long long& totalSeconds) {
    absSeconds = totalSeconds;
}  
void CTime::setMinutes(const int& m) {
    absSeconds = (absSeconds - (getMinutes() * 60)) + (m * 60);
}
void CTime::setSeconds(const int& s) {
    absSeconds = (absSeconds - getSeconds()) + s;
}
void CTime::setHours(const int& h) {
    absSeconds = (absSeconds % 3600) + (h * 3600);
}