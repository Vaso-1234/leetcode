class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0, r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int h;

            if (height[l] < height[r]) {
                h = height[l++];
            } else {
                h = height[r--];
            }

            int area = h * (r - l + 1);
            if (area > ans) ans = area;
        }

        return ans;
    }
};
