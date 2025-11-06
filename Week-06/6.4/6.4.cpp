#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void Read_And_Write_Prime_Numbers(const std::string& Path_Input, const std::string& Path_Output) {
    std::ifstream ifs(Path_Input);
    std::ofstream ofs(Path_Output);

    if (!ifs.is_open() || !ofs.is_open()) {
        std::cout << "Error: Cannot open file.\n";
        return;
    }

    std::istream_iterator<int> it_begin(ifs), it_end;
    std::ostream_iterator<int> out(ofs, "\n");

    std::copy_if(it_begin, it_end, out, isPrime);
}

int main() {
    Read_And_Write_Prime_Numbers("INPUT.txt", "OUTPUT.txt");

    return 0;
}