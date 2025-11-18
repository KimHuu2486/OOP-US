#include "SavingAccount.h"
#include <iostream>

int main()
{
    SavingAccount sa(1000, 12, 6.0f);

    sa.increaseDuration();
    sa.increaseDuration();

    sa.depositSaving(500);

    std::cout << sa.getBalance() << std::endl;

    return 0;
}