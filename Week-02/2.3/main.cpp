#include "function.h"

int main(){
    Student st;
    try {
        st.input();
    }
    catch (const runtime_error&e){
        cout << e.what() << endl;
    }
    st.output();

    cout << st.calculateGPA() << endl;
    cout << st.grade() << endl;

    st.setName("Tran Kim Huu");
    st.setLit(9.6);
    st.setMath(10);
    st.output();
    return 0;
}