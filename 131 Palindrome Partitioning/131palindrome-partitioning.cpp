class Solution {
public:
    
    void solve(int index, string &s,
               vector<string> &current,
               vector<vector<string>> &ans,
               vector<vector<bool>> &dp) {
        
        if (index == s.length()) {
            ans.push_back(current);
            return;
        }
        
        for (int i = index; i < s.length(); i++) {
            if (dp[index][i]) {
                current.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, current, ans, dp);
                current.pop_back();  
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> current;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                
                if (len == 1)
                    dp[i][j] = true;
                else if (len == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
        solve(0, s, current, ans, dp);
        return ans;
    }
};
