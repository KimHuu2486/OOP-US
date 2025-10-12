#include "function.h"
bool Student::isNumber(string s){
    bool dot = 0;
    for (char c: s){
        if (!isdigit(c)){
            if (c == '.') {
                if (dot) {
                    return false;
                }
                dot = true;
            }
            else return false;
        }
    }
    return true;
}
void Student::input(){
    cout << "Input student information (name, literature and math points):" << endl;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string temp;
    while (ss>>temp){
        if (isNumber(temp)) {
            lit = stof(temp);
            ss>>temp;
            math = stof(temp);
            break;
        }
        name += " " + temp;
    }
    if (name.size() == 0) {
        throw runtime_error("Error input!!!");
    }
    if (lit < 0 || lit > 10 || math < 0 || math > 10) {
        throw runtime_error("Error input!!!");
    }
    name = name.substr(1);
}
void Student::output(){
    cout << "Name: " << name << "; Lit: " << lit << "; Math: " << math << endl;
}
string Student::getName(){
    return name;
}
void Student::setName(string newName){
    name = newName;
}
float Student::getLit(){
    return lit;
}
void Student::setLit(float newLit){
    if (newLit >= 0 && newLit <= 10){
        lit = newLit;
    }
}
float Student::getMath(){
    return math;
}
void Student::setMath(float newMath){
    if (newMath >= 0 && newMath <= 10) {
        math = newMath;
    }
}
float Student::calculateGPA(){
    return (lit + math)/2;
}
string Student::grade(){
    float GPA = calculateGPA();
    if (GPA >= 9.0) {
        return "A";
    }
    else if (GPA >= 7.0) {
        return "B";
    }
    else if (GPA >= 5.0) {
        return "C";
    }
    else return "D";
}