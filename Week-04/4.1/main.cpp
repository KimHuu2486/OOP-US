#include "Fraction.h"

int main () {
    Fraction f1;             
    Fraction f2(5);           
    Fraction f3(f2);            

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;
    std::cout << "f3 = " << f3 << std::endl;

    std::cout << "\nNhap phan so f4: ";
    Fraction f4;
    std::cin >> f4;
    std::cout << "f4 = " << f4 << std::endl;

    Fraction a(1, 3), b(2, 5);
    std::cout << "\na = " << a << "b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;

    Fraction x(1, 4), y(2, 3);
    std::cout << "\nx = " << x << "y = " << y << std::endl;
    std::cout << "x > y ? " << (x > y) << std::endl;
    std::cout << "x < y ? " << (x < y) << std::endl;
    std::cout << "x == y ? " << (x == y) << std::endl;
    std::cout << "x != y ? " << (x != y) << std::endl;
    std::cout << "x >= y ? " << (x >= y) << std::endl;
    std::cout << "x <= y ? " << (x <= y) << std::endl;

    Fraction m(1, 2), n(2, 3);
    std::cout << "\nm = " << m << "n = " << n << std::endl;
    m = n;
    std::cout << "Sau m = n: m = " << m << std::endl;
    m += Fraction(1, 2);
    std::cout << "Sau m += 1/2: m = " << m << std::endl;
    m *= n;
    std::cout << "Sau m *= n: m = " << m << std::endl;

    Fraction t(3, 4);
    std::cout << "\nt = " << t << std::endl;
    std::cout << "++t = " << ++t << std::endl;
    std::cout << "t++ = " << t++ << std::endl;
    std::cout << "Sau khi t++: t = " << t << std::endl;

    Fraction z(5, 2);
    std::cout << "\nz = " << z << std::endl;
    std::cout << "(float)z = " << (float)z << std::endl;
    std::cout << "(int)z = " << (int)z << std::endl;

    return 0;
}