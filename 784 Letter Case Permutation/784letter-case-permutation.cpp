class Solution {
public:
    vector<string> result;

    void backtrack(string &s, int index) {
        if (index == s.size()) {
            result.push_back(s);
            return;
        }

        if (isalpha(s[index])) {
            s[index] = tolower(s[index]);
            backtrack(s, index + 1);
            s[index] = toupper(s[index]);
            backtrack(s, index + 1);
        } else {
            backtrack(s, index + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return result;
    }
};
