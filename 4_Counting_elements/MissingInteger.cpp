#include <unordered_set>

int solution(vector<int> &A) {
    std::unordered_set<int> numbers_in_A;
    numbers_in_A.reserve(A.size());
    for (auto &a : A)
        numbers_in_A.insert(a);
        
    int MAX_NUMBER = 1000000;
    for (int i = 1; i <= MAX_NUMBER; ++i)
        if (numbers_in_A.find(i) == numbers_in_A.end())
            return i;
    return 1;
}
