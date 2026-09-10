class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hDist, vDist;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDist.insert(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vDist.insert(vFences[j] - vFences[i]);
            }
        }

        long long best = -1;

        for (int d : hDist) {
            if (vDist.count(d)) {
                best = max(best, (long long)d);
            }
        }

        if (best == -1) return -1;

        return (best * best) % MOD;
    }
};
