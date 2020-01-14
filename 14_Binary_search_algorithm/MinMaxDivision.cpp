#include <algorithm>
#include <cmath>
#include <numeric>

int blocksNeeded(vector<int> A, int maxBlock) {
    int blockSum = 0;
    int blocks = 1;

    for (auto &a : A) {
        blockSum += a;
        if (blockSum > maxBlock) {
            blockSum = a;
            blocks++;
        }
    }

    return blocks;
}

int solution(int K, int M, vector<int> &A) {
    int mls_min = *std::max_element(A.begin(), A.end());
    int mls_max = std::accumulate(A.begin(), A.end(), 0);

    int mls = 0;

    if (K == 1) return mls_max;
    int N = A.size();
    if (K >= N) return mls_min;
    while (mls_min <= mls_max) {
        int mls_try = (int)((mls_max + mls_min) / 2.);
        if (blocksNeeded(A, mls_try) <= K) {
            mls_max = mls_try - 1;
            mls = mls_try;
        } else
            mls_min = mls_try + 1;
    }
    return mls;
}
