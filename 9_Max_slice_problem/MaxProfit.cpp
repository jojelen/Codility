int solution(vector<int> &A) {
    if (A.empty()) return 0;

    int minimum_price = A[0];
    int max_profit = 0;

    for (auto &a : A) {
        if (a < minimum_price) minimum_price = a;
        if (a - minimum_price > max_profit) max_profit = a - minimum_price;
    }
    return max_profit;
}
