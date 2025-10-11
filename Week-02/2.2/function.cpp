#include "function.h"
//Hàm kiểm tra số nguyên, số thập phân, phân số
bool Monomial::isNumber(string s) {
    if (s.empty()) return false;

    int dot = 0, slash = 0;
    int start = 0;

    if (s[0] == '-' || s[0] == '+') start = 1;

    for (int i = start; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) continue;

        if (c == '.') {
            dot++;
            if (dot > 1 || slash > 0) return false;
        } 
        else if (c == '/') {
            slash++;
            if (slash > 1) return false; 
        } 
        else {
            return false;
        }
    }

    return true;
}
void Monomial::input(){
    cout<<"Input coefficient and exponent of monomial: ";
    cin>>coef>>expo;
    if (!isNumber(coef) || !isNumber(expo))
        throw runtime_error("Error input");
};
void Monomial::output(){
    cout<<coef<<"x^"<<expo<<endl;
}
float getCoef();
void setCoef(int newCoef);
float getExpo();
void setExpo(int newExpo);
float evaluate(float base);
Monomial derive();
Monomial mul(Monomial seccondMono);