class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());
        vector<int> vals(n), pos(n);
        for (int i = 0; i < n; i++) {
            vals[i] = arr[i].first;
            pos[arr[i].second] = i;
        }
        vector<int> comp(n, 0);
        int cid = 0;
        for (int i = 1; i < n; i++) {
            if (vals[i] - vals[i - 1] > maxDiff) cid++;
            comp[i] = cid;
        }
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && vals[r + 1] - vals[i] <= maxDiff) r++;
            nxt[i] = r;
            if (r < i + 1) r = i + 1;
        }
        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) up[0][i] = nxt[i];
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int l = pos[u], rr = pos[v];

            if (l == rr) {
                ans.push_back(0);
                continue;
            }

            if (l > rr) swap(l, rr);
            if (comp[l] != comp[rr]) {
                ans.push_back(-1);
                continue;
            }
            int cur = l;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < rr) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            ans.push_back(steps + 1);
        }

        return ans;
    }
};