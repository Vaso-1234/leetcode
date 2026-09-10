class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int first = nums[0];          
        int minSecond = nums[1];      
        int ans = INT_MAX;

        for (int j = 2; j < n; j++) {
            ans = min(ans, first + minSecond + nums[j]);
            minSecond = min(minSecond, nums[j]);
        }

        return ans;
    }
};
