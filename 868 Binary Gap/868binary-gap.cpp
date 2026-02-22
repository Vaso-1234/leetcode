class Solution {
public:
    int binaryGap(int n) {

        int prev = -1;  
        int pos = 0;     
        int maxDist = 0;

        while (n > 0) {

            if (n & 1) {           
                if (prev != -1) {
                    maxDist = max(maxDist, pos - prev);
                }
                prev = pos;
            }

            pos++;
            n >>= 1;
        }

        return maxDist;
    }
};