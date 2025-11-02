#include <iostream>
#include "Polynomial.h"

int main() {
    double coef1[] = {1, 2, 3};
    Polynomial p1(2, coef1);
    std::cout << "p1(x) = " << p1 << std::endl;

    double coef2[] = {5, -4, 2, 1};
    Polynomial p2(3, coef2);
    std::cout << "p2(x) = " << p2 << std::endl;

    Polynomial p3(p2);
    std::cout << "p3(x) (copy of p2) = " << p3 << std::endl;

    std::cout << "p1 + p2 = " << (p1 + p2) << std::endl;
    std::cout << "p2 - p1 = " << (p2 - p1) << std::endl;
    std::cout << "p1 * p2 = " << (p1 * p2) << std::endl;

    Polynomial p4;
    p4 = p1;
    std::cout << "p4 = p1 -> p4(x) = " << p4 << std::endl;

    std::cout << "p1 == p4 ? " << (p1 == p4 ? "true" : "false") << std::endl;
    std::cout << "p1 != p2 ? " << (p1 != p2 ? "true" : "false") << std::endl;
    std::cout << "p1 < p2 ?  " << (p1 < p2  ? "true" : "false") << std::endl;
    std::cout << "p1 > p2 ?  " << (p1 > p2  ? "true" : "false") << std::endl;
    std::cout << "p1 <= p2 ? " << (p1 <= p2 ? "true" : "false") << std::endl;
    std::cout << "p1 >= p4 ? " << (p1 >= p4 ? "true" : "false") << std::endl;

    Polynomial d1 = !p2;
    Polynomial i1 = ~p1;
    std::cout << "p2'(x) = " << d1 << std::endl;
    std::cout << "Integral of p1(x) = " << i1 << std::endl;

    Polynomial p5;
    std::cout << "Nhap da thuc p5 theo dinh dang:\n";
    std::cin >> p5;
    std::cout << "p5(x) = " << p5 << std::endl;

    return 0;
}
