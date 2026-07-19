class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> lastIndex(26);

        // Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> used(26, false);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Skip if already present
            if (used[ch - 'a'])
                continue;

            // Remove larger characters if they appear later
            while (!ans.empty() &&
                   ans.back() > ch &&
                   lastIndex[ans.back() - 'a'] > i) {

                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            used[ch - 'a'] = true;
        }

        return ans;
    }
};