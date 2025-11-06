#include <bits/stdc++.h>

class Power {
    int m_exp;
public:
    Power(int exp): m_exp(exp) {}

    float operator()(float base) {
        float ans = 1;
        for (int i = 1; i<= m_exp; i++) {
            ans *= base;
        }
        return ans;
    }
};

class EvenCounter {
    int m_count;
public:
    EvenCounter(int start): m_count(start) {}
    int operator()(int value) {
        if (value % 2 == 0)
            ++m_count;
        return m_count;
    }
};


int main() {
    // Power square(2), cube(3);
    // float x = square(3); 
    // float y = cube(4); 
    // std::cout << x << " " << y << "\n";

    // std::vector<int> v {1, 2, 3, 4, 5};
    // EvenCounter count(0);
    // for (auto e : v)
    //     count(e);
    // std::cout << count(1);  

    // std::vector<std::string> words = {"C++", "is", "fun"};
    // std::string result = std::accumulate(
    //     std::next(words.begin()), words.end(),
    //     words[0],
    //     [](const std::string& a, const std::string& b) {
    //         return a + " " + b;
    //     }
    // );
    // std::cout << result;

    // std::vector<int> src = {1, 2, 3, 4, 5, 6};
    // std::vector<int> even;
    // std::copy_if(src.begin(), src.end(), std::back_inserter(even),
    //          [](int x){ return x % 2 == 0; });
    // for (int x: even) {
    //     std::cout << x << " ";
    // }

    std::string s = "abc123";
    bool has_digit = std::find_if(s.begin(), s.end(), ::isdigit) != s.end();
    std::cout << (has_digit ? "Contains number" : "No number");


    return 0;
}