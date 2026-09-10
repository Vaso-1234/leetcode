class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }

        int openPenalty = 0;  
        int closedPenalty = totalY; 

        int minPenalty = closedPenalty;
        int bestHour = 0;

        for (int j = 1; j <= n; j++) {
            if (customers[j - 1] == 'Y') {
                closedPenalty--;
            } else {
                openPenalty++;
            }

            int penalty = openPenalty + closedPenalty;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
