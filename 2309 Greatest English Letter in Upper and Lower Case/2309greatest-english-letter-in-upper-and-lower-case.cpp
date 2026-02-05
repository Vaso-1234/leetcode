class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }

        for (int i = 25; i >= 0; i--) {
            if (lower[i] && upper[i]) {
                char res = 'A' + i;
                return string(1, res);
            }
        }

        return "";
    }
};
