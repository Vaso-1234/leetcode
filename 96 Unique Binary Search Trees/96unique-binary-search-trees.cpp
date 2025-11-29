class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  

        for (int nodes = 1; nodes <= n; ++nodes) {
            long long ways = 0;
            for (int root = 1; root <= nodes; ++root) {
                ways += dp[root - 1] * dp[nodes - root];
            }
            dp[nodes] = ways;
        }

        return (int)dp[n];
    }
};
