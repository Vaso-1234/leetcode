class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long NEG_INF = -1e18;
        vector<long long> idle(k + 1, NEG_INF),
                          holdLong(k + 1, NEG_INF),
                          holdShort(k + 1, NEG_INF);

        idle[0] = 0;

        for (int price : prices) {
            vector<long long> newIdle = idle;
            vector<long long> newLong = holdLong;
            vector<long long> newShort = holdShort;

            for (int t = 0; t <= k; t++) {
                newLong[t] = max(holdLong[t], idle[t] - price);
                newShort[t] = max(holdShort[t], idle[t] + price);

                if (t > 0) {
                    newIdle[t] = max({
                        idle[t],
                        holdLong[t - 1] + price,   
                        holdShort[t - 1] - price   
                    });
                }
            }

            idle = newIdle;
            holdLong = newLong;
            holdShort = newShort;
        }

        return *max_element(idle.begin(), idle.end());
    }
};
