class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int cnt = 0;
            int d1 = 0, d2 = 0;

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    cnt++;
                    d1 = i;
                    d2 = x / i;
                    if (cnt > 1) break; 
                }
            }

            if (cnt == 1 && d1 != d2) {
                ans += (1 + d1 + d2 + x);
            }
        }

        return ans;
    }
};
