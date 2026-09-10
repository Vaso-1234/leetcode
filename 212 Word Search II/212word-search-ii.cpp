class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            memset(children, 0, sizeof(children));
            word = "";
        }
    };

    vector<string> result;
    int m, n;
    vector<vector<char>>* boardPtr;

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }

    void dfs(int i, int j, TrieNode* node) {
        char c = (*boardPtr)[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();
        }

        (*boardPtr)[i][j] = '#';  

        if (i > 0) dfs(i - 1, j, node);
        if (j > 0) dfs(i, j - 1, node);
        if (i < m - 1) dfs(i + 1, j, node);
        if (j < n - 1) dfs(i, j + 1, node);

        (*boardPtr)[i][j] = c; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& w : words)
            insert(root, w);

        boardPtr = &board;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, root);
            }
        }

        return result;
    }
};
