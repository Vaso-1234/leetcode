class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        for(int x : nums)
            s.insert(x);

        int longest = 0;

        for(int x : s) {
            
            if(s.find(x - 1) == s.end()) {   
                
                int curr = x;
                int length = 1;

                while(s.find(curr + 1) != s.end()) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};