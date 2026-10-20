
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int start = 0; start < n && ok; start += k) {
                int descents = 0;

                for (int i = start; i < start + k - 1; i++) {
                    if (nums[i] > nums[i + 1])
                        descents++;
                }

                if (descents > 1) {
                    ok = false;
                    break;
                }

                if (descents == 1 &&
                    nums[start + k - 1] > nums[start]) {
                    ok = false;
                }
            }

            if (ok) {
                vector<int> rotated = nums;

                for (int start = 0; start < n; start += k) {
                    int len = k;
                    int pivot = start;

                    while (pivot < start + len - 1 &&
                           nums[pivot] <= nums[pivot + 1]) {
                        pivot++;
                    }

                    if (pivot < start + len - 1) {
                        rotate(rotated.begin() + start,
                               rotated.begin() + pivot + 1,
                               rotated.begin() + start + len);
                    }
                }

                if (is_sorted(rotated.begin(), rotated.end()))
                    ans += k;
            }
        }

        return ans;
    }
};
