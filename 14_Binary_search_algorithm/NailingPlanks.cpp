#include <string>
#include <vector>

int NailedPlanks(vector<int> &A, vector<int> &B, vector<int> &C, int J) {
    int nailedPlanks = 0;
    int M = C.size();
    int N = A.size();

    vector<int> sumOfNails(2 * M + 1, 0);  // 0000111122222223333333
    for (int j = 0; j < J; ++j) sumOfNails[C[j]] = 1;

    for (int pos = 1; pos < 2 * M + 1; ++pos) {
	sumOfNails[pos] = sumOfNails[pos - 1] + sumOfNails[pos];
    }

    for (unsigned int k = 0; k < A.size(); ++k) {
	if (sumOfNails[B[k]] > sumOfNails[A[k] - 1]) nailedPlanks++;
    }

    if (nailedPlanks < N)
	return -1;
    else
	return nailedPlanks;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N = A.size();
    int M = C.size();

    int J_min = 1;
    int J_max = M;
    if (NailedPlanks(A, B, C, J_max) < N) return -1;
    int J = 0;

    while (J_min <= J_max) {
	int J_try = (int)((J_min + J_max) / 2.);
	int nailedPlanks = NailedPlanks(A, B, C, J_try);
	if (nailedPlanks >= 0) {
	    J_max = J_try - 1;
	    J = J_try;
	} else
	    J_min = J_try + 1;
    }
    return J;
}
