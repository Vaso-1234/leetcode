
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= min(n, i + 3); j++) {

                int cost = costs[j - 1] + (j - i) * (j - i);

                dp[j] = min(dp[j], dp[i] + cost);
            }
        }

        return dp[n];
    }
};

