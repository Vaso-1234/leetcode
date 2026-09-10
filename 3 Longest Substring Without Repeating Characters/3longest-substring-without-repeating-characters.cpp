#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);

        int n = s.size();
        int maxLen = 0;
        int start = 0; 

        for (int end = 0; end < n; end++) {
            char c = s[end];

            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }

            lastIndex[c] = end;  
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

