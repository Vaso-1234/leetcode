class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long streak = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (i > 0 && prices[i - 1] - prices[i] == 1) {
                streak++;
            } else {
                streak = 1;
            }
            ans += streak;
        }

        return ans;
    }
};
