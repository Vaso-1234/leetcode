class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 0;
        if (cnt.count(1)) {
            if (cnt[1] % 2)
                ans = max(ans, cnt[1]);
            else
                ans = max(ans, cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {

            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {

                if (!cnt.count(cur))
                    break;

                if (cnt[cur] >= 2) {
                    len += 2;

                    if (cur > 1000000000LL / cur)
                        break;

                    cur *= cur;
                }
                else {
                    len += 1;
                    break;
                }
            }

            if (len % 2 == 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};