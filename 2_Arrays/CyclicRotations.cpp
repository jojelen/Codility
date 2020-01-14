vector<int> solution(vector<int> &A, int K) {
    if (A.empty() == false) {
        for (int i = 0; i < K; ++i) {
            int lastElement = A.back();
            for (unsigned int j = A.size() - 1; j > 0; --j) {
                A[j] = A[j - 1];
            }
            A[0] = lastElement;
        }
    }
    return A;
}
