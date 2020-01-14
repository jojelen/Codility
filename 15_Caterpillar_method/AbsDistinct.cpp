// 100 %  O(N) or O(N*logN)
#include <unordered_set>

int solution(vector<int> &A) {
    std::unordered_set<int> absolutes;
    for (auto &a : A)
    {
        if (a < 0)
            absolutes.insert(-a);
        else
            absolutes.insert(a);
    }
    return absolutes.size();
}
