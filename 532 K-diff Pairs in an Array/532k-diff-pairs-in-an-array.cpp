class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int count = 0;

        if (k == 0) {
            for (auto &p : freq) {
                if (p.second >= 2)
                    count++;
            }
        } else {
            for (auto &p : freq) {
                if (freq.count(p.first + k))
                    count++;
            }
        }

        return count;
    }
};
