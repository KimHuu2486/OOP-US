#include "Array.h"

int main() {
    Array<int> arr1;
    Array<int> arr2(5);
    int temp[5] = {1, 2, 3, 4, 5};
    Array<int> arr3(temp, 5);
    Array<int> arr4(arr3);

    arr1.print();
    arr2.print();
    arr3.print();
    arr4.print();
    return 0;
}