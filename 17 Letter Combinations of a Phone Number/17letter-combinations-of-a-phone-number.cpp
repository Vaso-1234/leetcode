class Solution {
public:
    vector<string> res;
    vector<string> mapping = {
        "",    "",    "abc", "def", 
        "ghi", "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string &curr) {
        if (index == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            backtrack(digits, index + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr = "";
        backtrack(digits, 0, curr);
        return res;
    }
};
