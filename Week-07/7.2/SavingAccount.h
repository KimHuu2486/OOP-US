#pragma once

#include "Account.h"

class SavingAccount : public Account {
private:
    int m_month;
    float m_rate;
    int m_duration;
public:
    SavingAccount(float balance = 0, int month = 1, float rate = 4.0f) 
        : Account(balance), m_month(month), m_rate(rate), m_duration(0) {}

    float calcInterest() const {
        float monthlyRate = m_rate / 100.0f / 12.0f;
        return getBalance() * monthlyRate * m_duration;
    }

    void updateInterest() {
        float interest = calcInterest();
        if (interest > 0) {
            deposit(interest);
        }
        m_duration = 0;
    }

    void depositSaving(float money) {
        updateInterest();
        deposit(money);
    }

    bool withdrawSaving(float money) {
        updateInterest();
        return withdraw(money);
    }

    void increaseDuration() {
        m_duration++;
    }
};