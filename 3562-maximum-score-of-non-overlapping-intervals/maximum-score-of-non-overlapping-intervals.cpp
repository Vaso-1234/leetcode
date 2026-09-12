class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1],
                    intervals[i][2], i};
        }

        sort(a.begin(), a.end());

        vector<vector<pair<long long, vector<int>>>> dp(n + 1,
            vector<pair<long long, vector<int>>>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];

                int l = i + 1, r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (a[mid][0] > a[i][1])
                        r = mid;
                    else
                        l = mid + 1;
                }

                int next = l;

                long long score = a[i][2] + dp[next][k - 1].first;
                vector<int> cur = dp[next][k - 1].second;
                cur.push_back(a[i][3]);
                sort(cur.begin(), cur.end());

                if (score > dp[i][k].first ||
                    (score == dp[i][k].first && cur < dp[i][k].second)) {
                    dp[i][k] = {score, cur};
                }
            }
        }

        return dp[0][4].second;
    }
};