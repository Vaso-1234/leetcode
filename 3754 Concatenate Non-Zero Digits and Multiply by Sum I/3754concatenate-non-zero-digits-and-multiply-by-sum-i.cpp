class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string nonZero = "";
        int sum = 0;

        for (char ch : s) {
            if (ch != '0') {
                nonZero += ch;
                sum += (ch - '0');
            }
        }

        if (nonZero == "") return 0;

        long long x = stoll(nonZero);
        return x * sum;
    }
};