class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        const long long MOD = 1e9 + 7;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        sort(freq.rbegin(), freq.rend());

        int distinct = 0;

        for (int x : freq) {
            if (x > 0)
                distinct++;
        }

        if (distinct < k)
            return 0;

        int limit = freq[k - 1];
        int need = 0;
        int total = 0;

        for (int x : freq) {
            if (x > limit)
                need++;
            else if (x == limit)
                total++;
        }

        long long ans = 1;

        for (int i = 0; i < need; i++)
            ans = ans * freq[i] % MOD;

        for (int i = 0; i < k - need; i++)
            ans = ans * limit % MOD;

        long long ways = 1;

        for (int i = 0; i < k - need; i++) {
            ways = ways * (total - i) % MOD;
            ways = ways * modInverse(i + 1, MOD) % MOD;
        }

        return ans * ways % MOD;
    }

    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);
    }

    long long power(long long a, long long b, long long mod) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }
};