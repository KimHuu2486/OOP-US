#include "function.h"
int main(){
    Monomial mono1;
    try {
        mono1.input();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    mono1.output();
    cout << mono1.getCoef() << " " << mono1.getExpo() << endl;
    
    try {
        cout << mono1.evaluate(-2) << endl;
    }
    catch (const runtime_error& e){
        cout << e.what() << endl;
    }

    Monomial mono2 = mono1.derive();
    mono2.output();

    mono1.mul(mono2).output();
    return 0;
}