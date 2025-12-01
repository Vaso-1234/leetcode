class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;
        for (int b : batteries) high += b;  
        
        high /= n;  

        while (low < high) {
            long long mid = (low + high + 1) / 2;  

            if (canRun(mid, n, batteries))
                low = mid; 
            else
                high = mid - 1;  
        }

        return low;
    }

    bool canRun(long long T, int n, vector<int>& batteries) {
        long long total = 0;

        for (long long b : batteries)
            total += min(b, T);

        return total >= T * n;
    }
};
