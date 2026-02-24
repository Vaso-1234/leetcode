class Solution {
public:
    
    int getNext(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;   
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool dir = nums[i] > 0;  

            while (true) {

                int nextSlow = getNext(nums, slow);
                int nextFast = getNext(nums, fast);
            
                if (nums[nextSlow] == 0 || nums[nextFast] == 0 ||
                   (nums[nextSlow] > 0) != dir ||
                   (nums[nextFast] > 0) != dir)
                    break;

                nextFast = getNext(nums, nextFast);

                if (nums[nextFast] == 0 ||
                   (nums[nextFast] > 0) != dir)
                    break;

                slow = nextSlow;
                fast = nextFast;
                if (slow == fast) {
                    if (slow == getNext(nums, slow))
                        break;

                    return true;
                }
            }
            int valDir = nums[i] > 0;
            int j = i;

            while (nums[j] != 0 && (nums[j] > 0) == valDir) {
                int next = getNext(nums, j);
                nums[j] = 0;
                j = next;
            }
        }

        return false;
    }
};