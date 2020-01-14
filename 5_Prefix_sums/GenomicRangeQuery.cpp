int imp(const char &c) {
    if (c == 'A')
        return 1;
    else if (c == 'C')
        return 2;
    else if (c == 'G')
        return 3;
    else  // T
        return 4;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    int M = P.size();

    vector<vector<int>> NucCount(N, {0, 0, 0, 0});

    vector<int> quaries(M, 0);

    NucCount[0][imp(S[0]) - 1]++;
    for (int n = 1; n < N; ++n) {
        for (int a = 0; a < 4; ++a) NucCount[n][a] = NucCount[n - 1][a];
        NucCount[n][imp(S[n]) - 1]++;
    }

    for (int m = 0; m < M; ++m) {
        if (P[m] == Q[m]) {
            quaries[m] = imp(S[P[m]]);
        } else if (P[m] == 0) {
            for (int a = 0; a < 4; ++a)
                if (NucCount[Q[m]][a] > 0) {
                    quaries[m] = a + 1;
                    break;
                }
        } else
            for (int a = 0; a < 4; ++a) {
                if (NucCount[Q[m]][a] - NucCount[P[m] - 1][a] > 0) {
                    quaries[m] = a + 1;
                    break;
                }
            }
    }

    return quaries;
}
