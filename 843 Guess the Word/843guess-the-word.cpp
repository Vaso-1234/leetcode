/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
 class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;

        while (!candidates.empty()) {
            string guessWord = pickWord(candidates);
            int matches = master.guess(guessWord);

            if (matches == 6) return;  // Found the secret

            vector<string> next;
            for (string& w : candidates) {
                if (match(guessWord, w) == matches) {
                    next.push_back(w);
                }
            }
            candidates = next;
        }
    }

    int match(const string& a, const string& b) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i]) cnt++;
        }
        return cnt;
    }

    // Minimax strategy
    string pickWord(vector<string>& candidates) {
        int minWorst = INT_MAX;
        string best = candidates[0];

        for (string& w1 : candidates) {
            vector<int> cnt(7, 0);
            for (string& w2 : candidates) {
                cnt[match(w1, w2)]++;
            }
            int worst = *max_element(cnt.begin(), cnt.end());
            if (worst < minWorst) {
                minWorst = worst;
                best = w1;
            }
        }
        return best;
    }
};

