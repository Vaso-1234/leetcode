class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> arr;

        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            arr.push_back(gcd(nums[i], mx));
        }

        sort(arr.begin(), arr.end());

        long long ans = 0;

        int i = 0;
        int j = n - 1;

        while (i < j) {
            ans += gcd(arr[i], arr[j]);
            i++;
            j--;
        }

        return ans;
    }
};