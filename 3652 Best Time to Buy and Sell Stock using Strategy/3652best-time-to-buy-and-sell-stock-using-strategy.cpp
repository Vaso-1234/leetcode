class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        // Prefix sum of strategy[i] * prices[i]
        vector<long long> prefOrig(n + 1, 0);
        // Prefix sum of prices[i]
        vector<long long> prefPrice(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefOrig[i + 1] = prefOrig[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }

        long long baseProfit = prefOrig[n];
        long long bestGain = 0;
        int half = k / 2;

        // Sliding window
        for (int l = 0; l + k <= n; l++) {
            int mid = l + half;
            int r = l + k;

            // Original contribution of window
            long long original = prefOrig[r] - prefOrig[l];

            // Modified contribution (only last k/2 sells)
            long long modified = prefPrice[r] - prefPrice[mid];

            bestGain = max(bestGain, modified - original);
        }

        return baseProfit + bestGain;
    }
};
