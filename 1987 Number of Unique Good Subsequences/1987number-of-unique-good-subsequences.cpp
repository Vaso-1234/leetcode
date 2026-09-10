class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;
        long long zero = 0, one = 0;
        bool hasZero = false;

        for (char c : binary) {
            if (c == '0') {
                zero = (zero + one) % MOD;
                hasZero = true;
            } else {
                one = (one + zero + 1) % MOD;
            }
        }

        return (one + zero + hasZero) % MOD;
    }
};