class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> temp = freq;
        int pos = -1;

        for (int i = 0; i < target.size(); i++) {
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (temp[j] > 0) {
                    pos = i;
                    break;
                }
            }

            if (temp[target[i] - 'a'] == 0)
                break;

            temp[target[i] - 'a']--;
        }

        if (pos == -1)
            return "";

        string ans;

        for (int i = 0; i < pos; i++) {
            ans += target[i];
            freq[target[i] - 'a']--;
        }

        int x = target[pos] - 'a' + 1;

        while (freq[x] == 0)
            x++;

        ans += char('a' + x);
        freq[x]--;

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                ans += char('a' + i);
                freq[i]--;
            }
        }

        return ans;
    }
};