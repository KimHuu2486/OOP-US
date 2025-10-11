#include "function.h"

int main() {
    
    int n;
    cout << "Enter number of fractions: ";
    cin >> n;
    while (n <= 0) {
        cout << "Number is invalid, please enter again: ";
        cin >> n;
    }
    Fraction* arr = new Fraction[n];

    for (int i = 0; i < n; i++) {
        cout << "Fraction " << i + 1 << ":" << endl;
        inputFraction(arr[i]);
    }

    cout << "\nYou entered the fractions:" << endl;
    for (int i = 0; i < n; i++) {
        outputFraction(arr[i]);
    }

    sort(arr, n, ascending<Fraction>);
    cout << "\nSorted fractions in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        outputFraction(arr[i]);
    }

    delete[] arr;

    int nums1[] = {5, 2, 9, 1, 3};
    int size1 = 5;
    sort(nums1, size1, descending<int>);
    cout << "\nIntegers sorted descending:\n";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    double nums2[] = {5.2, 2.1, 9.5, 1.3, 3.7};
    int size2 = 5;
    sort(nums2, size2, ascending<double>);
    cout << "\nDoubles sorted ascending:\n";
    for (double x : nums2) cout << x << " ";
    cout << endl;

    return 0;
}