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
    Student(const std::string&);
    Student(const std::string&, const float&, const float&);
    Student(const Student&);
    ~Student();
    //Test các khai báo
    void output();
};

#endif