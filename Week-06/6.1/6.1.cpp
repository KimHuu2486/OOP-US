#include "init_vector.h"

int main() {
    int N = 10;

    init_vector list1;
    list1.initEvenOddList(N);
    list1.print();
    
    init_vector list2;
    list2.initPrimeList(N);
    list2.print();

    return 0;
}