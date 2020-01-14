// 100% solution O(N*logN)
#include <unordered_set>
#include <cmath>
#include <algorithm>

vector<int> solution(vector<int> &A) {
    int N = A.size();
    
    int max_A = *std::max_element(A.begin(), A.end());
    vector<int> counter(max_A + 1, 0);
    for (auto &a : A)
        ++counter[a];
        
	// Set of divisors for each number
    vector<std::unordered_set<int>> divisors(max_A + 1, std::unordered_set<int>{1});
	// All numbers have themselves as divisor
    for (int i = 2; i <= max_A; ++i)
        if (counter[i] > 0)
            divisors[i].insert(i);
        
    int i = 2;
    int sqrtmaxA = std::sqrt(max_A);
    while (i  <= sqrtmaxA)
    {
        int k = i * i;
        while (k <= max_A)
        {
            if (counter[k] > 0)
                divisors[k].insert(i);
            k += i;
        }
        ++i;
    }
    
	// Adding additional divisors above sqrt(max_A)
    for (int l = max_A; l > 0;  --l)
    {
        if (counter[l] > 0)
        {
            vector<int> newDivisors;
            for (auto & divisor : divisors[l])
            {
                newDivisors.push_back(l / divisor);
            }
            divisors[l].insert(newDivisors.begin(), newDivisors.end());
        }
    }
    
	// Translating to non-divisors
    vector<int> nonDivisors(N, 0);
    for (int m = 0; m < N; ++m)
    {
        nonDivisors[m] = N;
        for (auto &divisor : divisors[A[m]])
            nonDivisors[m] -= counter[divisor];
    }
    
    return nonDivisors;
}


