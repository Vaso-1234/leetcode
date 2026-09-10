class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        set<int> s(nums.begin(), nums.end());

        while (s.find(sum) != s.end())
            sum++;

        return sum;
    }
};