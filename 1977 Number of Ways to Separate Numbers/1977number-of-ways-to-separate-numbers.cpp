class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfCombinations(string num) {
        int n = num.size();

        if (num[0] == '0')
            return 0;

        vector<vector<int>> lcp(n + 1, vector<int>(n + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (num[i] == num[j])
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<vector<int>> pref(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; i++) {
            for (int len = 1; len <= i; len++) {
                int start = i - len;

                if (num[start] == '0') {
                    dp[i][len] = 0;
                }
                else if (start == 0) {
                    dp[i][len] = 1;
                }
                else {
                    dp[i][len] = pref[start][min(len - 1, start)];

                    if (len <= start) {
                        int prevStart = start - len;

                        if (num[prevStart] != '0') {
                            int common = lcp[prevStart][start];

                            if (common >= len ||
                                num[prevStart + common] <= num[start + common]) {
                                dp[i][len] += dp[start][len];

                                if (dp[i][len] >= MOD)
                                    dp[i][len] -= MOD;
                            }
                        }
                    }
                }

                pref[i][len] = pref[i][len - 1] + dp[i][len];

                if (pref[i][len] >= MOD)
                    pref[i][len] -= MOD;
            }
        }

        return pref[n][n];
    }
};