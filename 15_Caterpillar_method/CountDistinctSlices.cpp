// 100% O(N) solution
int solution(int M, vector<int> &A) {
    int back = 0;
    int front = 0;
    int N = A.size();
    vector<bool> counter(M + 1, false);
    long unique_slices = 0;
    while (front < N) {
        // moving the front
        while (front < N && counter[A[front]] == false) {
            // Counting subslices ending at front
            unique_slices += front - back + 1;
            counter[A[front]] = true;
            ++front;
        }

        // moving the back
        while (back < front && A[back] != A[front]) {
            counter[A[back]] = false;
            ++back;
        }

        if (back < N - 1) {
            counter[A[back]] = false;
            ++back;
        }
    }
    if (unique_slices > 1e9)
        return 1e9;
    else
        return unique_slices;
}
