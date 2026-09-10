class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxNum + 1, 0);
        for (int x : nums)
            freq[x]++;
        vector<long long> divisible(maxNum + 1, 0);

        for (int i = 1; i <= maxNum; i++) {
            for (int j = i; j <= maxNum; j += i) {
                divisible[i] += freq[j];
            }
        }
        vector<long long> gcdCount(maxNum + 1, 0);

        for (int i = maxNum; i >= 1; i--) {

            long long cnt = divisible[i];
            gcdCount[i] = cnt * (cnt - 1) / 2;
            for (int j = 2 * i; j <= maxNum; j += i) {
                gcdCount[i] -= gcdCount[j];
            }
        }
        vector<long long> prefix(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; i++) {
            prefix[i] = prefix[i - 1] + gcdCount[i];
        }
        vector<int> ans;
        for (long long q : queries) {
            int left = 1, right = maxNum;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (prefix[mid] >= q + 1)
                    right = mid;
                else
                    left = mid + 1;
            }
            ans.push_back(left);
        }
        return ans;
    }
};