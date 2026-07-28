class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> f(26, 0);

        for (char c : s)
            f[c - 'a']++;

        string l = "", m = "";

        for (int i = 0; i < 26; i++) {
            l += string(f[i] / 2, 'a' + i);

            if (f[i] % 2)
                m = char('a' + i);
        }

        string r = l;
        reverse(r.begin(), r.end());

        return l + m + r;
    }
};


