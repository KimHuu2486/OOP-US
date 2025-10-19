#include "Student.h"

int main() {
    Student st1("TranKimHuu");
    Student st2;
    Student st3("Tran Kim Huu", 9.0, 8.5);
    Student st4(st3);

    st1.output();
    st2.output();
    st3.output();
    st4.output();
    return 0;
}