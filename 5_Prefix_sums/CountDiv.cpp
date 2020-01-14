#include <cmath>

int solution(int A, int B, int K) {
    if (A % K == 0)
        return (int)std::floor((B - A) / K) + 1;
    else
        return (int)std::floor((B - (A - (A % K))) / K);
}
