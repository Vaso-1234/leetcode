class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> rows;

        for (auto seat : reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9)
                rows[seat[0]] |= (1 << seat[1]);
        }

        int ans = (n - rows.size()) * 2;

        for (auto row : rows) {
            int mask = row.second;

            bool left = (mask & (1 << 2)) == 0 &&
                        (mask & (1 << 3)) == 0 &&
                        (mask & (1 << 4)) == 0 &&
                        (mask & (1 << 5)) == 0;

            bool right = (mask & (1 << 6)) == 0 &&
                         (mask & (1 << 7)) == 0 &&
                         (mask & (1 << 8)) == 0 &&
                         (mask & (1 << 9)) == 0;

            bool middle = (mask & (1 << 4)) == 0 &&
                          (mask & (1 << 5)) == 0 &&
                          (mask & (1 << 6)) == 0 &&
                          (mask & (1 << 7)) == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans++;
        }

        return ans;
    }
};