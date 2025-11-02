#include "bits/stdc++.h"
using namespace std;

void TowerOfHanot(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    TowerOfHanot(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    TowerOfHanot(n - 1, auxiliary, destination, source);
}

int main() {
    int n = 3; // Number of disks
    TowerOfHanot(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}