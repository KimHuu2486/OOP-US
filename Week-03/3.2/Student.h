#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string m_name;
    float m_math, m_lit;
public:
    Student();
    Student(const std::string& name);
    Student(const std::string& name, const float& math, const float& lit);
    Student(const Student& st);
    ~Student();
    //Test các khai báo
    void output();
};

#endif