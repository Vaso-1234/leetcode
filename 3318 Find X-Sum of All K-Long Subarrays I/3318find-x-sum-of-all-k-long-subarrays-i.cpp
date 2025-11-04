class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            
            if (i >= k) {
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0)
                    freq.erase(nums[i - k]);
            }

            if (i >= k - 1) {
                vector<pair<int, int>> freqList;
                for (auto &p : freq) {
                    freqList.push_back({p.second, p.first});
                }

                sort(freqList.begin(), freqList.end(), [](auto &a, auto &b) {
                    if (a.first == b.first) return a.second > b.second;
                    return a.first > b.first;
                });

                int total = 0;
                unordered_set<int> keep;
                for (int j = 0; j < freqList.size() && j < x; j++)
                    keep.insert(freqList[j].second);

                for (int t = i - k + 1; t <= i; t++) {
                    if (keep.count(nums[t])) total += nums[t];
                }

                ans.push_back(total);
            }
        }

        return ans;
    }
};
