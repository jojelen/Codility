// 100 % solution O(N logN)
#include <climits>

int solution(vector<int> &A) {
    int maxFibonacci = 24;
    vector<int> fib(maxFibonacci + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= maxFibonacci; ++i) fib[i] = fib[i - 2] + fib[i - 1];

    int N = A.size();
    vector<int> minSteps(N + 2, -1);
    // Inserting "ground" at edges. A is then size N + 2
    A.insert(A.begin(), 1);
    A.push_back(1);

    minSteps[0] = 0;
    for (int i = 0; i < N + 2; ++i) {
        // If this place could be reached from previous jumps
        if (A[i] == 1 && minSteps[i] != -1) {
            // Noting where it can jump to next
            for (auto &jump : fib) {
                if (i + jump < N + 2)
                    if (A[i + jump] == 1) {
                        if (minSteps[i + jump] == -1)
                            minSteps[i + jump] = minSteps[i] + 1;
                        else
                            minSteps[i + jump] =
                                std::min(minSteps[i + jump], minSteps[i] + 1);
                    }
            }
        }
    }

    return minSteps.back();
}
