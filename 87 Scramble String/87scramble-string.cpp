class Solution {
public:

    bool solve(string &s1, string &s2, int i, int j, int len,
               vector<vector<vector<int>>> &dp) {
        if (dp[i][j][len] != -1)
            return dp[i][j][len];
        if (s1.substr(i, len) == s2.substr(j, len))
            return dp[i][j][len] = true;
        for (int k = 1; k < len; k++) {
            bool noSwap =
                solve(s1, s2, i, j, k, dp) &&
                solve(s1, s2, i + k, j + k, len - k, dp);
            bool swap =
                solve(s1, s2, i, j + len - k, k, dp) &&
                solve(s1, s2, i + k, j, len - k, dp);

            if (noSwap || swap)
                return dp[i][j][len] = true;
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length())
            return false;

        int n = s1.length();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n + 1, -1)
            )
        );

        return solve(s1, s2, 0, 0, n, dp);
    }
};

