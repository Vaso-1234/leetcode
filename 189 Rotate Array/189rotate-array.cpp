class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 

        auto reversePart = [&](int start, int end) {
            while (start < end) {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        };

        reversePart(0, n - 1);
        reversePart(0, k - 1);
        reversePart(k, n - 1);
    }
};
