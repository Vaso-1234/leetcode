class Solution {
public:
    int longestConsecutive(vector<int>& bars) {
        if (bars.empty()) return 1;

        sort(bars.begin(), bars.end());
        int maxLen = 1, curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxLen = max(maxLen, curr);
        }

        return maxLen + 1;
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {
        int maxH = longestConsecutive(hBars);
        int maxV = longestConsecutive(vBars);

        int side = min(maxH, maxV);
        return side * side;
    }
};
