class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> next(k, 0);

            next[x % k]++;

            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nr = (r * (x % k)) % k;
                    next[nr] += dp[r];
                }
            }

            for (int r = 0; r < k; r++)
                ans[r] += next[r];

            dp = next;
        }

        return ans;
    }
};