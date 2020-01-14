#include <cstdio>

vector<int> F(int N) {
    vector<int> f(N + 1, 0);
    int i = 2;
    while (i * i <= N) {
        if (f[i] == 0) {
            int k = i * i;
            while (k <= N) {
                if (f[k] == 0) f[k] = i;
                k += i;
            }
        }
        i++;
    }

    return f;
}

int factors(int x, vector<int> &f) {
    int primeFactors = 1;
    while (f[x] > 0) {
        primeFactors += 1;
        x /= f[x];
    }

    return primeFactors;
}
vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<int> primeFactors(N + 1, 0);
    vector<int> f = F(N);

    for (int i = 1; i <= N; ++i) primeFactors[i] = factors(i, f);

    vector<int> numberOfSemiPrimes(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        numberOfSemiPrimes[i] = numberOfSemiPrimes[i - 1];
        if (primeFactors[i] == 2) numberOfSemiPrimes[i]++;
    }

    vector<int> quaries(P.size(), 0);
    for (unsigned int k = 0; k < quaries.size(); ++k)
        quaries[k] = numberOfSemiPrimes[Q[k]] - numberOfSemiPrimes[P[k] - 1];

    return quaries;
}
