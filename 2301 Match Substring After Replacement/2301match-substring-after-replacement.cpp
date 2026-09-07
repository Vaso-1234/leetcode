class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool can[128][128] = {};

        for (auto &m : mappings)
            can[m[0]][m[1]] = true;

        for (int i = 0; i + sub.size() <= s.size(); i++) {
            bool ok = true;

            for (int j = 0; j < sub.size(); j++) {
                char a = sub[j];
                char b = s[i + j];

                if (a != b && !can[a][b]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return true;
        }

        return false;
    }
};