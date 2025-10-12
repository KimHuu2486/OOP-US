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
//Hàm cắt bỏ số 0 ở cuối phần thập phân
string Monomial::trimZeros(string s) {
    s.erase(s.find_last_not_of('0') + 1, string::npos);
    if (!s.empty() && s.back() == '.') s.pop_back();
    return s;
}
void Monomial::input(){
    cout << "Input coefficient and exponent of monomial: ";
    cin >> coef >> expo;
    if (!isNumber(coef) || !isNumber(expo))
        throw runtime_error("Error input");
};
void Monomial::output(){
    cout << coef << "x^" << expo << endl;
}
float Monomial::getCoef(){
    if (coef.find("/")!=string::npos){
        int idx = coef.find("/");
        float numerator = stof(coef.substr(0, idx));
        float denominator = stof(coef.substr(idx + 1, coef.size() - idx - 1));
        return numerator / denominator;
    }
    return stof(coef);
}
void Monomial::setCoef(string newCoef){
    if (isNumber(newCoef)){
        coef = newCoef;
    }
}
float Monomial::getExpo(){
    if (expo.find("/")!=string::npos){
        int idx = expo.find("/");
        float numerator = stof(expo.substr(0, idx));
        float denominator = stof(expo.substr(idx + 1, expo.size() - idx - 1));
        return numerator / denominator;
    }
    return stof(expo);
}
void Monomial::setExpo(string newExpo){
    if (isNumber(newExpo)) {
        expo = newExpo;
    }
}
float Monomial::evaluate(float base){
    float result = pow(base, getExpo());
    //Kiểm tra điều kiện xác định
    if (isnan(result)){
        throw runtime_error("INVALID");
    }
    return getCoef() * result;
}
Monomial Monomial::derive(){
    Monomial ans;
    float oriCoef = getCoef();
    float oriExpo = getExpo();
    //Trường hợp số mũ  = 0
    if (oriExpo == 0) {
        ans.expo = "0";
        ans.coef = "0";
    }
    else {
        ans.expo = trimZeros(to_string(oriExpo - 1));
        ans.coef = trimZeros(to_string(oriCoef * oriExpo));
    }
    return ans;
}
Monomial Monomial::mul(Monomial seccondMono){
    Monomial ans;
    float coef1 = getCoef();
    float expo1 = getExpo();
    float coef2 = seccondMono.getCoef();
    float expo2 = seccondMono.getExpo();
    ans.coef = trimZeros(to_string(coef1 * coef2));
    ans.expo = trimZeros(to_string(expo1 + expo2));
    return ans;
}