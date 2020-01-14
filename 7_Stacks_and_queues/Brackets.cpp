#include <vector>

int solution(string &S) {
    vector<char> s;

    for (auto &c : S) {
        if (!s.empty()) {
            if (c == ')' && s.back() == '(')
                s.pop_back();
            else if (c == ']' && s.back() == '[')
                s.pop_back();
            else if (c == '}' && s.back() == '{')
                s.pop_back();
            else
                s.push_back(c);
        } else
            s.push_back(c);
    }
    if (s.size() == 0 || S.empty())
        return 1;
    else
        return 0;
}
