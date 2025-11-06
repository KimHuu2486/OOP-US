#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string &s)
{
    std::string filtered;
    
    // Copy nếu là kí tự chữ cái hoặc số
    std::copy_if(s.begin(), s.end(), std::back_inserter(filtered), [](char c)
                 { return isalnum(c); });

    // Chuyển các thành kí tự thường
    std::transform(filtered.begin(), filtered.end(), filtered.begin(), [](char c)
                   { return tolower(c); });

    return std::equal(filtered.begin(), filtered.begin() + filtered.size() / 2, filtered.rbegin());
}

int main()
{
    std::string s = "A man, a plan, a canal, Panama!";
    std::cout << isPalindrome(s) << std::endl;

    return 0;
}