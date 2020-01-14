// 100 % O(N^2) solution. N < 1e3

#include <algorithm>

int solution(vector<int> &A) {
    int N = A.size();

    if (N < 3) return 0;

    std::sort(A.begin(), A.end());

    int triangles = 0;
    for (int back = 0; back < N; ++back) {
        int mid = back + 1;
        int front = back + 2;
        // A[front] + A[mid] > A[back]
        // and A[front] + A[back] > A[mid]
        // are always valid for sorted array.
        while (mid < N - 1) {
            while (front < N && A[back] + A[mid] > A[front]) ++front;
            triangles += front - mid - 1;
            ++mid;
        }
    }
    return triangles;
}

