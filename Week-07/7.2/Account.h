#pragma once

class Account {
private:
    float m_balance;
public:
    Account(const int& balance) : m_balance(balance) {}

    float getBalance() const {
        return m_balance;
    }
    void deposit(float money) {
        m_balance += money;
    }
    bool withdraw(float money) {
        if (money > m_balance) {
            return false;
        }
        m_balance -= money;
        return true;
    } 
};