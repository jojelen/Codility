// 100% O(N) solution
int solution(int K, vector<int> &A) {
    int N = A.size();
    int ropeLength = 0;
    int ropes = 0;
    for (int i = 0; i < N; ++i) {
        ropeLength += A[i];
        if (ropeLength >= K) {
            ropes++;
            ropeLength = 0;
        }
    }
    return ropes;
}
