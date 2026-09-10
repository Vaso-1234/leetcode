class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < r; i++) {
            for (int j = 0; j + 2 < c; j++) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool isMagic(vector<vector<int>>& g, int x, int y) {
        vector<int> seen(10, 0);

        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = 1;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (g[x + i][y] + g[x + i][y + 1] + g[x + i][y + 2] != 15)
                return false;
        }
        for (int j = 0; j < 3; j++) {
            if (g[x][y + j] + g[x + 1][y + j] + g[x + 2][y + j] != 15)
                return false;
        }

        if (g[x][y] + g[x + 1][y + 1] + g[x + 2][y + 2] != 15)
            return false;
        if (g[x][y + 2] + g[x + 1][y + 1] + g[x + 2][y] != 15)
            return false;

        return true;
    }
};
