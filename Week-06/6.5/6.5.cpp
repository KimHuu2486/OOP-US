#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

void CountStudentsByGPA(const std::vector<std::pair<std::string, float>> &students)
{
    std::map<float, int> gpaCount;

    for (const auto &cur : students)
    {
        gpaCount[cur.second]++;
    }

    std::vector<std::pair<int, int>> counts(gpaCount.begin(), gpaCount.end());

    std::sort(counts.begin(), counts.end(), [](const auto &a, const auto &b)
              { return a.second > b.second; });

    for (const auto &cur : counts)
    {
        std::cout << "GPA " << cur.first << ": " << cur.second << " student" << (cur.second > 1 ? "s.\n" : ".\n");
    }
}

int main()
{
    std::vector<std::pair<std::string, float>> students = {
        {"John", 7}, {"Eve", 9}, {"Ander", 7}, {"Dora", 8}, {"Tom", 7}, {"Alex", 9}};

    CountStudentsByGPA(students);

    return 0;
}