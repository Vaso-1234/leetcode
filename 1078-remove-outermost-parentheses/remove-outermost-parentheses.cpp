class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                // Add '(' only if we are already inside a primitive
                if (depth > 0)
                    ans += c;

                depth++;
            }
            else {
                depth--;

                // Add ')' only if we are still inside a primitive
                if (depth > 0)
                    ans += c;
            }
        }

        return ans;
    }
};