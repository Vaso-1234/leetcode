class Solution {
public:

    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return ((long long)p.first << 32) ^ p.second;
        }
    };

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<pair<int,int>, int, hash_pair> mp;
            int currMax = 0;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
                if (dx == 0) dy = 1;
                if (dy == 0) dx = 1;

                pair<int,int> slope = {dx, dy};

                currMax = max(currMax, ++mp[slope]);
            }

            ans = max(ans, currMax + 1);
        }

        return ans;
    }
};