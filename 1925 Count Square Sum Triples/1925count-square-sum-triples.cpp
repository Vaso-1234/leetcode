class Solution {
public:
    int countTriples(int n) {
        int limit = n * n;
        vector<bool> isSquare(limit + 1, false);

        for (int c = 1; c <= n; ++c) {
            isSquare[c * c] = true;
        }

        int count = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int sum = a * a + b * b;
                if (sum <= limit && isSquare[sum]) {
                    count++;
                }
            }
        }

        return count;
    }
};
