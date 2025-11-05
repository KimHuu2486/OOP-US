#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

int main () {
    std::ifstream f("input.txt");
    auto f_begin = std::istream_iterator<int>(f);
    auto f_end   = std::istream_iterator<int>();
    auto o       = std::ostream_iterator<int>(std::cout, "\n");

    for (auto i = f_begin; i != f_end; ++i)
        *o = *i;

    f.clear();                 
    f.seekg(0, std::ios::beg);
    std::vector<int> v;
    auto o1 = std::back_inserter(v);

    for (auto i = f_begin; i != f_end; ++i)
        *o1 = *i;
    
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
