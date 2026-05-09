class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> arr;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // Extract top row
            for (int j = left; j <= right; j++)
                arr.push_back(grid[top][j]);

            // Extract right column
            for (int i = top + 1; i < bottom; i++)
                arr.push_back(grid[i][right]);

            // Extract bottom row
            for (int j = right; j >= left; j--)
                arr.push_back(grid[bottom][j]);

            // Extract left column
            for (int i = bottom - 1; i > top; i--)
                arr.push_back(grid[i][left]);

            int len = arr.size();

            int rot = k % len;

            int idx = rot;
            for (int j = left; j <= right; j++) {
                grid[top][j] = arr[idx];
                idx = (idx + 1) % len;
            }

            for (int i = top + 1; i < bottom; i++) {
                grid[i][right] = arr[idx];
                idx = (idx + 1) % len;
            }
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = arr[idx];
                idx = (idx + 1) % len;
            }

            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = arr[idx];
                idx = (idx + 1) % len;
            }
        }

        return grid;
    }
};