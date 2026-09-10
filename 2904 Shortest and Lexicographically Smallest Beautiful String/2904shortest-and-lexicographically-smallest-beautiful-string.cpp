class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int cnt = 0;
        int l = 0;

        int mn = INT_MAX;
        string ans = "";

        for (int r = 0; r < n; r++) {
            if (s[r] == '1')
                cnt++;

            while (cnt > k) {
                if (s[l] == '1')
                    cnt--;
                l++;
            }

            if (cnt == k) {
                while (s[l] == '0')
                    l++;

                int len = r - l + 1;
                string curr = s.substr(l, len);

                if (len < mn) {
                    mn = len;
                    ans = curr;
                }
                else if (len == mn) {
                    ans = min(ans, curr);
                }
            }
        }

        return ans;
    }
};