class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int totalLetters = 0;

            while (j < n && totalLetters + words[j].size() + (j - i) <= maxWidth) {
                totalLetters += words[j].size();
                j++;
            }

            int numWords = j - i;
            int spaces = maxWidth - totalLetters;
            string line;

            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1)
                        line += " ";
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int gaps = numWords - 1;
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int count = spacesPerGap + (extraSpaces > 0 ? 1 : 0);
                        line += string(count, ' ');

                        if (extraSpaces > 0)
                            extraSpaces--;
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};