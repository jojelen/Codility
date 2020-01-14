int solution(vector<int> &A) {
    int candidate = A[0];
    int count = 0;
    int N = A.size();
    for (auto &a : A) {
        if (count == 0) {
            candidate = a;
            count++;
        } else {
            if (a == candidate)
                count++;
            else
                count--;
        }
    }

    count = 0;
    for (auto &a : A) {
        if (a == candidate) count++;
    }
    float minCount = N / 2.;
    if (count <= minCount) return 0;

    int equiLeader = 0;
    int count_so_far = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == candidate) count_so_far++;
        if (count_so_far > (i + 1) / 2. &&
            (count - count_so_far) > (N - 1 - i) / 2.)
            equiLeader++;
    }
    return equiLeader;
}
