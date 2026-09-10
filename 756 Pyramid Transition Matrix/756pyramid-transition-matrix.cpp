class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }

    bool dfs(string curr) {
        if (memo.count(curr)) return memo[curr];

        if (curr.size() == 1) return memo[curr] = true;

        vector<string> nextRows;
        buildNextRows(curr, 0, "", nextRows);

        for (string &next : nextRows) {
            if (dfs(next)) {
                return memo[curr] = true;
            }
        }

        return memo[curr] = false;
    }

    void buildNextRows(string &curr, int idx, string path, vector<string>& nextRows) {
        if (idx == curr.size() - 1) {
            nextRows.push_back(path);
            return;
        }

        string key = curr.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            buildNextRows(curr, idx + 1, path + c, nextRows);
        }
    }
};
