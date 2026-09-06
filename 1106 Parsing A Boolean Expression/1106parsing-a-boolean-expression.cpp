class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return solve(expression, i);
    }

    bool solve(string& s, int& i) {
        char op = s[i++];

        if (op == 't')
            return true;

        if (op == 'f')
            return false;

        i++;

        if (op == '!') {
            bool val = solve(s, i);
            i++;
            return !val;
        }

        bool ans = (op == '&');

        while (s[i] != ')') {
            if (s[i] == ',') {
                i++;
                continue;
            }

            bool val = solve(s, i);

            if (op == '&')
                ans &= val;
            else
                ans |= val;
        }

        i++;
        return ans;
    }
};