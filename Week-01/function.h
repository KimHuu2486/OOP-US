#include <iostream>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

template <typename T>
using sortCriteria = bool (*)(const T&, const T&);

void inputFraction(Fraction& f);
void outputFraction(const Fraction& f);

int compareFraction(const Fraction& f1, const Fraction& f2);
//Định nghĩa toán tử so sánh cho kiểu Fraction
inline bool operator<(const Fraction& f1, const Fraction& f2) {
    return compareFraction(f1, f2) < 0;
}
inline bool operator>(const Fraction& f1, const Fraction& f2) {
    return compareFraction(f1, f2) > 0;
}

template <typename T>
bool ascending(const T& a, const T& b) {
    return a < b;
}

template <typename T>
bool descending(const T& a, const T& b) {
    return a > b;
}

template <typename T>
void sort(T* arr, int n, sortCriteria<T> cmp) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int  j = i - 1;
        while (j >= 0 && cmp(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}