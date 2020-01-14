int solution(vector<int> &A) {
    int max_slice = A[0];
    int max_prev_slice = A[0];
    int N = A.size(); // in  [1,1e6]
    for (int i = 1; i < N; ++i)
    {
        max_prev_slice = std::max(A[i], A[i] +  max_prev_slice);
        if (max_prev_slice > max_slice)
            max_slice = max_prev_slice;
    }
    return max_slice;
}
