class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int total = 1 << n;

        vector<long long> LCM(total, 1);

        for (int mask = 1; mask < total; mask++) {
            int bit = __builtin_ctz(mask);
            int prev = mask & (mask - 1);

            LCM[mask] = lcm(LCM[prev], coins[bit]);

            if (LCM[mask] > 1e18)
                LCM[mask] = 1e18;
        }

        auto count = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < total; mask++) {
                if (LCM[mask] > x)
                    continue;

                long long ways = x / LCM[mask];

                if (__builtin_popcount(mask) & 1)
                    ans += ways;
                else
                    ans -= ways;
            }

            return ans;
        };

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};;