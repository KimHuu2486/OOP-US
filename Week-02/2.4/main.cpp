#include "function.h"

int main() {
    Array arr1;
    try {
        arr1.input();
    }
    catch (const runtime_error& e){
        cout << e.what() << endl;
    }
    arr1.output();
    cout << arr1.getSize() << endl;
    
    arr1.setSize(7);
    arr1.output();

    arr1.setElement(2, 10);
    cout << arr1.getElement(2) << endl;

    cout << arr1.find(4) << endl;

    arr1.sort(acsending);
    arr1.output();
    arr1.sort(desending);
    arr1.output();

    arr1.deleteArray();

    return 0;
}