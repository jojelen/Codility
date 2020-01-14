// 100% O(N) solution
struct NonoverlapSet {
    vector<int> StartPoints;
    vector<int> EndPoints;

    int size = 0;

    void addSegment(int start, int end) {
        if (size == 0) {
            StartPoints.push_back(start);
            EndPoints.push_back(end);
            ++size;
        } else {
            if (start >= StartPoints.back() &&
                end <= EndPoints.back())  // Exchanging for a shorter segment
            {
                StartPoints.back() = start;
                EndPoints.back() = end;
            } else if (start > EndPoints.back())  // NonOverlapping
            {
                StartPoints.push_back(start);
                EndPoints.push_back(end);
                ++size;
            }
        }
    }
};

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();

    NonoverlapSet segments;
    for (int i = 0; i < N; ++i) segments.addSegment(A[i], B[i]);

    return segments.size;
}
