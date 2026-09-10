#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int x : nums) {
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            curMin = min(x, curMin + x);  
            minSum = min(minSum, curMin);

            totalSum += x;
        }

        if (maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};
