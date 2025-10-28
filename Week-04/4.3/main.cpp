#include "Array.h"

int main() {
    Array<int> a1;
    std::cout << "a1 = " << a1 << std::endl;

    Array<int> a2(5);
    std::cout << "a2 = " << a2 << std::endl;

    std::cout << "Nhap 5 so nguyen cho a2: ";
    std::cin >> a2;
    std::cout << "Mang a2 sau khi nhap: " << a2 << std::endl;

    Array<int> a3(a2);
    std::cout << "a3 = " << a3 << std::endl;

    Array<int> a4;
    a4 = a3;
    std::cout << "a4 = " << a4 << std::endl;

    a4[0] = 10;
    std::cout << "a4 = " << a4 << std::endl;
    std::cout << "a3 = " << a3 << std::endl;

    int* ptr = a4; 
    std::cout << ptr[0] << std::endl;

    return 0;
}