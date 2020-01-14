#include <climits>
#include <cmath>

int solution(int N) {
    int i = 1;
    int upperLimit = std::sqrt(N);
    int maxPerimiter = INT_MAX;
    while (i <= upperLimit)
    {
        if (N % i == 0)
            maxPerimiter = std::min(maxPerimiter, 2 * ( i + (N/i)));
        ++i;
    }
    return maxPerimiter;
}
