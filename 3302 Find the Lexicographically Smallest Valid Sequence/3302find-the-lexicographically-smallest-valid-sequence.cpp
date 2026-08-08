class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans;
        vector<int> right(m, -1);

        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                right[j] = i;
                j--;
            }
            i--;
        }

        bool changed = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!changed && (j == m - 1 || i < right[j + 1])) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};