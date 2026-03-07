class Solution {
public:
    int minFlips(string s) {

        int n = s.size();
        string t = s + s;

        int diff0 = 0, diff1 = 0;
        int ans = INT_MAX;

        for (int i = 0; i < t.size(); i++) {

            char p0 = (i % 2) ? '1' : '0'; 
            char p1 = (i % 2) ? '0' : '1'; 

            if (t[i] != p0) diff0++;
            if (t[i] != p1) diff1++;

            if (i >= n) {
                if (t[i-n] != ((i-n)%2 ? '1' : '0')) diff0--;
                if (t[i-n] != ((i-n)%2 ? '0' : '1')) diff1--;
            }

            if (i >= n-1) {
                ans = min(ans, min(diff0, diff1));
            }
        }

        return ans;
    }
};