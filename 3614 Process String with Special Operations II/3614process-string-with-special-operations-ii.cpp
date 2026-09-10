class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long INF = 4e18;

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = min(INF, len[i] + 1);
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = min(INF, len[i] * 2);
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        long long idx = k;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (idx == len[i + 1] - 1)
                    return ch;
            }
            else if (ch == '#') {
                if (len[i] > 0)
                    idx %= len[i];
            }
            else if (ch == '%') {
                idx = len[i] - 1 - idx;
            }
        }

        return '.';
    }
};