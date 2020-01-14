// 100% solution
//  New with max_element

#include <algorithm>

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> maximal_sum(N, 0);

    maximal_sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
	int prev_step = i - 6 > 0 ? i - 6 : 0;

	// Finding the previous mark with maximal sum
	int max_sum = *std::max_element(maximal_sum.begin() + prev_step,
					maximal_sum.begin() + i);
	maximal_sum[i] = max_sum + A[i];
    }

    return maximal_sum.back();
}

// Old
int solution(vector<int> &A) {
    int N = A.size();
    vector<int> maximal_sum(N, 0);

    maximal_sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
	int prev_step = i - 6 > 0 ? i - 6 : 0;

	// Finding the previous mark with maximal sum
	int max_sum = maximal_sum[prev_step];
	for (int j = prev_step + 1; j < i; ++j) {
	    if (maximal_sum[j] > max_sum) max_sum = maximal_sum[j];
	}

	maximal_sum[i] = max_sum + A[i];
    }

    return maximal_sum.back();
}

