// Finding number of unique numbers in vector
#include <unordered_set>

int solution(vector<int> &A) {
    std::unordered_set<int> numbers;
    for (auto &a : A)
        numbers.insert(a);
    return numbers.size();
}
