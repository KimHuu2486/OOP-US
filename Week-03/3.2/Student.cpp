#include "Student.h"

Student::Student():
    m_name(""),
    m_math(0),
    m_lit(0) {}

Student::Student(const std::string& name){
    m_name = name;
    m_math = 0;
    m_lit = 0;
}

Student::Student(const std::string& name, const float& math, const float& lit){
    m_name = name;
    if (math < 0 || math > 10 || lit < 0 || lit > 10) {
        std::cout << "Invalid at points!" << std::endl;
        m_math = 0;
        m_lit = 0;
    }
    else {
        m_math = math;
        m_lit = lit;
    }
}

Student::Student(const Student& st){
    m_name = st.m_name;
    m_math = st.m_math;
    m_lit = st.m_lit;
}

Student::~Student() {}

void Student::output() {
    std::cout<< m_name << "; " << "math = " << m_math << "; " << m_lit << std::endl;
}