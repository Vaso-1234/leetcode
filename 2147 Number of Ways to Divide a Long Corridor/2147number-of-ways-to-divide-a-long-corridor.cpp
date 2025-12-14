class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        vector<int> seats;

        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S')
                seats.push_back(i);
        }

        int totalSeats = seats.size();
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;

        long long ways = 1;

        for (int i = 2; i < totalSeats; i += 2) {
            int prev = seats[i - 1];
            int curr = seats[i];
            int plantsBetween = curr - prev - 1;
            ways = (ways * (plantsBetween + 1)) % MOD;
        }

        return ways;
    }
};
