#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string normalizeString(std::string s)
{
    // Xóa bỏ khoảng trắng ở đầu và cuối chuỗi

    auto start = std::find_if_not(s.begin(), s.end(), ::isspace);
    auto end = std::find_if_not(s.rbegin(), s.rend(), ::isspace).base();
    if (start < end)
    {
        s = std::string(start, end);
    }
    else
        return "";

    // Xóa bỏ khoảng trắng và dấu câu bị lặp

    s.erase(std::unique(s.begin(), s.end(), [](char a, char b)
                        { return (std::isspace(a) && std::isspace(b)) || (std::ispunct(a) && std::ispunct(b)); }),
            s.end());

    // Viết hoa chữ cái đầu của mỗi từ

    bool newWord = true;

    std::transform(s.begin(), s.end(), s.begin(), [&newWord](char c)
                   {
        if (std::isalpha(c)) {
            char result = newWord ? std::toupper(c) : std::tolower(c);
            newWord = false;
            return result;
        }
        newWord = std::isspace(c) || std::ispunct(c);
        return c; });

    return s;
}

int main()
{
    std::string s1 = "   [[[the  quick,,, brown  fox  ]]]  ";
    std::string s2 = normalizeString(s1);
    std::cout << s2 << "\n";
    return 0;
}