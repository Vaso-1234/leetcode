class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if (s.size() < k + (1 << k) - 1)
            return false;

        int need = 1 << k;
        vector<bool> seen(need, false);

        int mask = 0, allOnes = need - 1, count = 0;

        for (int i = 0; i < s.size(); i++) {

            mask = ((mask << 1) & allOnes) | (s[i] - '0');

            if (i >= k - 1 && !seen[mask]) {
                seen[mask] = true;
                if (++count == need)
                    return true;
            }
        }

        return false;
    }
};