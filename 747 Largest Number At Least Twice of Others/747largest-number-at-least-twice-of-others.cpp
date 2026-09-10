class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        
        int largest = -1, secondLargest = -1;
        int index = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
                index = i;
            } else if (nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }
        
        if (largest >= 2 * secondLargest) return index;
        return -1;
    }
};
