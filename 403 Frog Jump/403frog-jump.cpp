class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, unordered_set<int>> dp;

        for (int x : stones)
            dp[x] = {};

        dp[0].insert(0);

        unordered_set<int> stoneSet(stones.begin(), stones.end());

        for (int pos : stones) {
            for (int k : dp[pos]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump <= 0)
                        continue;

                    int next = pos + jump;

                    if (next == stones[n - 1])
                        return true;

                    if (stoneSet.count(next))
                        dp[next].insert(jump);
                }
            }
        }

        return false;
    }
};