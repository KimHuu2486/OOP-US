#include "Monomial.h"

int main() {
    Monomial m1;
    std::cout << "m1 = " << m1 << std::endl;

    Monomial m2(3.5, 2);
    Monomial m3(-1.2, 2);
    std::cout << "m2 = " << m2 << ", m3 = " << m3 << std::endl;

    Monomial m4(m2);
    std::cout << "m4 = " << m4 << std::endl;

    Monomial m5;
    m5 = m3;
    std::cout << "m5 = " << m5 << std::endl;

    std::cout << m2 << " + " << m3 << " = " << (m2 + m3) << std::endl;
    std::cout << m2 << " * " << m3 << " = " << (m2 * m3) << std::endl;

    std::cout << m2 << " < " << m3 << " ? " << (m2 < m3) << std::endl;
    std::cout << m2 << " > " << m3 << " ? " << (m2 > m3) << std::endl;
    std::cout << m2 << " == " << m3 << " ? " << (m2 == m3) << std::endl;
    std::cout << m2 << " != " << m3 << " ? " << (m2 != m3) << std::endl;

    Monomial m6(2.5, 2);
    Monomial m7(3, 3);
    std::cout << "m6 = " << m6 << std::endl;
    m6 += m3;
    std::cout << "m6 += m3, m6 = " << m6 << std::endl;
    m7 *= Monomial(2, 1);
    std::cout << "m7 *= Monomial(2, 1), m7 = " << m7 << std::endl;

    Monomial m8(1, 2);
    std::cout << "m8 = " << m8 << std::endl;
    std::cout << "++m8 = " << ++m8 << std::endl;
    std::cout << "m8++ = " << m8++ << std::endl;
    std::cout << "m8 = "<<  m8 << std::endl;
    std::cout << "--m8 = " << --m8 << std::endl;
    std::cout << "m8-- = " << m8--<< std::endl;
    std::cout << "m8 = "<<  m8 << std::endl;

    Monomial m9(2, 5);
    std::cout << "m9 = " << m9 << ", !m9 = " << !m9 << std::endl;

    return 0;
}