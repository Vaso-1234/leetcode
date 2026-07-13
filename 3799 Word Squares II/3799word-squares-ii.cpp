class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {

        unordered_map<string, vector<string>> mp;

        // key = first char + last char
        for (auto &w : words) {
            string key;
            key.push_back(w[0]);
            key.push_back(w[3]);
            mp[key].push_back(w);
        }

        vector<vector<string>> ans;

        for (auto &top : words) {
            for (auto &left : words) {

                if (top == left) continue;
                if (top[0] != left[0]) continue;

                string bottomKey;
                bottomKey.push_back(left[3]);

                for (char c = 'a'; c <= 'z'; c++) {
                    bottomKey.resize(1);
                    bottomKey.push_back(c);

                    if (!mp.count(bottomKey)) continue;

                    for (auto &bottom : mp[bottomKey]) {

                        if (bottom == top || bottom == left) continue;

                        string rightKey;
                        rightKey.push_back(top[3]);
                        rightKey.push_back(bottom[3]);

                        if (!mp.count(rightKey)) continue;

                        for (auto &right : mp[rightKey]) {

                            if (right == top || right == left || right == bottom)
                                continue;

                            ans.push_back({top, left, right, bottom});
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};