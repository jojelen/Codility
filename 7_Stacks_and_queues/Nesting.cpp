// 100% O(N) solution
void add_par(string &s, char c) {
    if (s.empty())
        s += c;
    else if (s.back() == '(' && c == ')')
        s.pop_back();
    else
        s += c;
}

int solution(string &S) {
    string stack = "";

    for (auto &c : S) add_par(stack, c);

    if (stack.size() == 0)
        return 1;
    else
        return 0;
}
