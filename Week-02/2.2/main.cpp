#include "function.h"
int main(){
    Monomial mono1;
    try {
        mono1.input();
    }
    catch (const runtime_error& e) {
        cout<<e.what()<<endl;
    }
    mono1.output();
}