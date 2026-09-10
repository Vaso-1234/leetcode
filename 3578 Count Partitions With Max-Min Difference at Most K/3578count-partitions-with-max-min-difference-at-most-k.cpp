class Solution {
public:
    static const long long MOD = 1000000007LL;

    int countPartitions(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<long long> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;

        deque<int> mn, mx;  
        int L = 0;     

        for (int idx = 0; idx < n; ++idx) {
            int x = nums[idx];
            while (!mn.empty() && nums[mn.back()] > x) mn.pop_back();
            mn.push_back(idx);
            while (!mx.empty() && nums[mx.back()] < x) mx.pop_back();
            mx.push_back(idx);

            while (!mn.empty() && !mx.empty() &&
                   nums[mx.front()] - nums[mn.front()] > k) {
                L++;
                if (!mn.empty() && mn.front() < L) mn.pop_front();
                if (!mx.empty() && mx.front() < L) mx.pop_front();
            }

            int i = idx + 1;
            long long total = pref[i - 1]; 
            long long remove = (L - 1 >= 0) ? pref[L - 1] : 0;

            dp[i] = (total - remove + MOD) % MOD;
            pref[i] = (pref[i - 1] + dp[i]) % MOD;
        }

        return (int)(dp[n] % MOD);
    }
};
