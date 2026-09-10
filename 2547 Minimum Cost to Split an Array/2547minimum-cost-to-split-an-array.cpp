class Solution {
public:
    long long minCost(vector<int>& nums, int k) {
        int n = nums.size();
        const long long INF = 1e18;

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            vector<int> freq(n + 1, 0);
            int trimmed = 0;

            for (int j = i; j >= 1; j--) {
                int x = nums[j - 1];

                if (freq[x] == 1)
                    trimmed += 2;
                else if (freq[x] >= 2)
                    trimmed++;

                freq[x]++;

                dp[i] = min(dp[i], dp[j - 1] + k + trimmed);
            }
        }

        return dp[n];
    }
};