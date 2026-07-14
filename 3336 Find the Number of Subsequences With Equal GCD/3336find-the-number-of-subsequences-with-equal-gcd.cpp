class Solution {
public:
    static const int MOD = 1000000007;

    int subsequencePairCount(vector<int>& nums) {
        const int MAX = 200;

        vector<vector<long long>> dp(MAX + 1, vector<long long>(MAX + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {

            vector<vector<long long>> next = dp;

            for (int g1 = 0; g1 <= MAX; g1++) {
                for (int g2 = 0; g2 <= MAX; g2++) {

                    if (dp[g1][g2] == 0)
                        continue;

                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
                    next[ng1][g2] = (next[ng1][g2] + dp[g1][g2]) % MOD;

                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
                    next[g1][ng2] = (next[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp = next;
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};