class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto &it : mp) {
            vector<int>& pos = it.second;
            int k = pos.size();

            vector<long long> prefix(k);
            prefix[0] = pos[0];

            for(int i = 1; i < k; i++) {
                prefix[i] = prefix[i-1] + pos[i];
            }

            for(int i = 0; i < k; i++) {
                
                long long left = 0, right = 0;

                if(i > 0) {
                    left = (long long)i * pos[i] - prefix[i-1];
                }

                if(i < k - 1) {
                    right = (prefix[k-1] - prefix[i]) - (long long)(k - i - 1) * pos[i];
                }

                ans[pos[i]] = left + right;
            }
        }

        return ans;
    }
};