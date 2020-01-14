// 100% O(N)
void add_fish(vector<vector<int>> &fishes, int A, int B) {
    if (fishes.empty()) {
        fishes.push_back(vector<int>{A, B});
        return;
    } else if (fishes.back()[1] == B)  // Same direction
    {
        fishes.push_back(vector<int>{A, B});
        return;
    } else if (fishes.back()[1] == 0)  // a B[i] = 0 meets a B[i+1] = 1
    {
        fishes.push_back(vector<int>{A, B});
        return;
    } else if (fishes.back()[1] == 1)  // a B[i] = 1 meets a B[i+1] = 0
    {
        if (fishes.back()[0] > A)
            return;
        else {
            fishes.pop_back();
            add_fish(fishes, A, B);
        }
    }
}

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();

    vector<vector<int>> fishes;

    for (int i = 0; i < N; ++i) {
        add_fish(fishes, A[i], B[i]);
    }

    return fishes.size();
}
