class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) return result;

        unordered_map<string, vector<string>> parent;
        unordered_map<string, int> level;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currLevel = level[word];

            string temp = word;
            for (int i = 0; i < wordLen; i++) {
                char orig = temp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp)) {
                        if (!level.count(temp)) {
                            level[temp] = currLevel + 1;
                            q.push(temp);
                            parent[temp].push_back(word);
                        } 
                        else if (level[temp] == currLevel + 1) {
                            parent[temp].push_back(word);
                        }
                    }
                }
                temp[i] = orig;
            }
        }

        if (!level.count(endWord)) return result;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, parent, path, result);

        return result;
    }

private:
    void dfs(string word, string& beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& result) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (string& p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path, result);
            path.pop_back();
        }
    }
};
