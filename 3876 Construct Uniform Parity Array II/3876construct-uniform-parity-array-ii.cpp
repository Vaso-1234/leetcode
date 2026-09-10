class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        int mn = nums1[0];

        for (int x : nums1) {
            mn = min(mn, x);

            if (x % 2 != 0)
                allEven = false;
        }

        return allEven || mn % 2 != 0;
    }
};


 