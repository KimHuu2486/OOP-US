#include <iostream>
using namespace std;
class Fraction {
private:
    int num, den;
public:
    Fraction() {
        num = 0;
        den = 1;
    }
    Fraction(int val){
        num = val;
        den = 1;
    }
    Fraction(int numerator, int denominator){
        num = numerator;
        den = denominator;
    }
    Fraction(const Fraction& p) {
        num = p.num;
        den = p.den;
    }
    void output(){
        cout << num << "/" << den << endl;
    };
};
int main() {
    Fraction p(2, 3);
    p.output();
    Fraction q(p);
    q.output();
    return 0;
}