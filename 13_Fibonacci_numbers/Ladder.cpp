#include <cmath>

vector<int> fibonacci(int n) {
    vector<int> fib(n + 1, 0);
    fib[0] = 1.;
    fib[1] = 1.;

    unsigned int limit = 1ULL << 30;
    for (int i = 2; i <= n; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % limit;
    return fib;
}
vector<int> solution(vector<int> &A, vector<int> &B) {
    int L = A.size();

    auto fib = fibonacci(L);

    vector<int> results(L, 0);
    for (int i = 0; i < L; ++i) {
        unsigned int divisor = 1ULL << B[i];
        results[i] = fib[A[i]] % divisor;
    }
    return results;
}
