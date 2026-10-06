class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else {
                balance--;

                if (balance < 0) {
                    ans++;
                    balance = 0;
                }
            }
        }

        return ans + balance;
    }
};