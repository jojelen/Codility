int solution(vector<int> &A) {
    int N = A.size();

    float minAvg = 10000;
    int minSliceStart = 0;

    for (int n = 0; n < N; ++n) {
        if (n < N - 1) {
            float Avg2 = (A[n] + A[n + 1]) / 2.;
            if (Avg2 < minAvg) {
                minAvg = Avg2;
                minSliceStart = n;
            }
        }
        if (n < N - 2) {
            float Avg3 = (A[n] + A[n + 1] + A[n + 2]) / 3.;
            if (Avg3 < minAvg) {
                minAvg = Avg3;
                minSliceStart = n;
            }
        }
    }

    return minSliceStart;
}
