#include "function.h"
void inputFraction(Fraction& f) {
    cout << "Enter numerator: ";
    cin >> f.numerator;
    cout << "Enter denominator: ";
    cin >> f.denominator;
    while (f.denominator == 0) {
        cout << "Denominator is invalid, please enter again: ";
        cin >> f.denominator;
    }
}
void outputFraction(const Fraction& f) {
    cout << f.numerator << "/" << f.denominator << endl;
}
int compareFraction(const Fraction& f1, const Fraction& f2) {
    int num1 = f1.numerator * f2.denominator;
    int num2 = f2.numerator * f1.denominator;
    if (num1 < num2) {
        return -1;
    }
    else if (num1 > num2) {
        return 1;
    }
    return 0;
}
