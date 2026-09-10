class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;

        for (int x : nums) {
            lo = max(lo, (long long)x);
            hi += x;
        }

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            int parts = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    parts++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if (parts <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};