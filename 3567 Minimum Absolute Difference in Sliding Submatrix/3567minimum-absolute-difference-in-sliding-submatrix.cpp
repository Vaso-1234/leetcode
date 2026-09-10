class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {

                vector<int> temp;

                for(int x = i; x < i + k; x++) {
                    for(int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }

                sort(temp.begin(), temp.end());

                int minDiff = INT_MAX;

                for(int t = 1; t < temp.size(); t++) {
                    if(temp[t] != temp[t-1])
                        minDiff = min(minDiff, abs(temp[t] - temp[t-1]));
                }

                if(minDiff == INT_MAX)
                    minDiff = 0;

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};