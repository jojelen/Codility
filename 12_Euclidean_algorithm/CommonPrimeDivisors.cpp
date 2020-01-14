// 100 % solution
#include <cmath>

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

bool allfactorsOfAareInB(int A, int B) {
    if (A == 1) return true;
    int common_factors = gcd(A, B);
    int X = A;
    while (common_factors > 1) {
        X = X / common_factors;
        if (X == 1) return true;
        common_factors = gcd(X, B);
    }
    return false;
}

int solution(vector<int> &A, vector<int> &B) {
    int results = 0;
    int Z = A.size();
    for (int i = 0; i < Z; ++i) {
        if (allfactorsOfAareInB(A[i], B[i]) && allfactorsOfAareInB(B[i], A[i]))
            ++results;
    }
    return results;
}

// This seem to be correct. But it is too slow!
#include <cmath>

bool sameDivisors(int A, int B) {
    // Print the number of 2s that divide n
    if (A % 2 != B % 2) return false;

    // Checking odd primes
    int max = std::max(A, B);
    for (int i = 3; i <= max; i += 2) {
        if (A % i == 0 && B % i != 0)
            return false;
        else if (B % i == 0 && A % i != 0)
            return false;

        while (A % i == 0) A /= i;
        while (B % i == 0) B /= i;
    }

    return true;
}

int solution(vector<int> &A, vector<int> &B) {
    int results = 0;
    int Z = A.size();
    for (int i = 0; i < Z; ++i) {
        if (sameDivisors(A[i], B[i])) ++results;
    }
    return results;
}

