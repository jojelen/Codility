#include <algorithm>
#include <cmath>
#include <cstdio>

int solution(vector<int> &A) {
    if (A.empty()) return -1;
    vector<int> B(A);
    std::sort(A.begin(), A.end());

    int N = A.size();
    int middle = (int)std::floor((N - 1) / 2.);
    int candidate = A[middle];

    int count = 1;
    for (int i = 1; i <= middle; ++i) {
        if (A[middle - i] == candidate) count++;
        if (A[middle + i] == candidate) count++;
    }
    if (count > N / 2.) {
        for (int i = 0; i < N; ++i)
            if (B[i] == candidate) return i;
    }
    return -1;
}
