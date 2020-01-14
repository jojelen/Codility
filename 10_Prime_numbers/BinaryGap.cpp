#include <bitset>
#include <string>

int solution(int N) {
    std::string Nbit = std::bitset<32>(N).to_string();

    int prev1 = -1;
    int longestGap = 0;
    for (int i = 1; i <= 32; i++) {
        if (Nbit[i] == '1') {
            if (prev1 > 0 && i - prev1 > 1) {
                int gap = i - prev1 - 1;
                if (gap > longestGap) longestGap = gap;
            }
            prev1 = i;
        }
    }
    return longestGap;
}
