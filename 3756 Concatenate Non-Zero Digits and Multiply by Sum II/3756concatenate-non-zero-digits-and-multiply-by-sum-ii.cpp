class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Store non-zero digits and their original positions
        vector<int> pos;
        string nz = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                nz += s[i];
            }
        }

        int m = nz.size();

        // Precompute powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10LL) % MOD;
        }

        // Prefix sum of digits
        vector<long long> prefSum(m + 1, 0);
        // Prefix concatenated value
        vector<long long> prefVal(m + 1, 0);

        for (int i = 0; i < m; i++) {
            int d = nz[i] - '0';
            prefSum[i + 1] = prefSum[i] + d;
            prefVal[i + 1] = (prefVal[i] * 10 + d) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // First non-zero position >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // First non-zero position > r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long sum = prefSum[R + 1] - prefSum[L];

            long long val = (prefVal[R + 1] - prefVal[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back((val * sum) % MOD);
        }

        return ans;
    }
};