class Solution {
public:
    int minPartitions(string n) {

        int maxDigit = 0;

        for (char c : n) {
            if (c == '9') return 9; 
            maxDigit = max(maxDigit, c - '0');
        }

        return maxDigit;
    }
};