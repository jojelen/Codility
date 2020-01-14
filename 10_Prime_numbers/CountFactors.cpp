#include <cmath>

int solution(int N) {
    int factors = 0;
    int i = 1;
    float sqrtN = std::sqrt(N);
    while (i < sqrtN) {
        if (N % i == 0) factors += 2;
        ++i;
    }
    if (i * i == N) factors++;
    return factors;
}
