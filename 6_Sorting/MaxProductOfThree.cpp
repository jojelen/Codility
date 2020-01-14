#include <algorithm>

int solution(vector<int> &A) {
    std::sort(A.begin(), A.end());

    int N = A.size();
    int max1 = A[N - 1] * A[N - 2] * A[N - 3];
    int max2 = A[0] * A[1] * A[N - 1];

    return std::max(max1, max2);
}
