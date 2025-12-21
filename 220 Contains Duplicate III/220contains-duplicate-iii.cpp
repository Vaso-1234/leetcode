class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;

        unordered_map<long long, long long> bucket;
        long long width = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {
            long long num = nums[i];
            long long id = getBucketId(num, width);

            if (bucket.count(id)) return true;

            if (bucket.count(id - 1) && llabs(num - bucket[id - 1]) <= valueDiff)
                return true;
            if (bucket.count(id + 1) && llabs(num - bucket[id + 1]) <= valueDiff)
                return true;

            bucket[id] = num;

            if (i >= indexDiff) {
                long long oldId = getBucketId(nums[i - indexDiff], width);
                bucket.erase(oldId);
            }
        }

        return false;
    }

private:
    long long getBucketId(long long x, long long width) {
        return x >= 0 ? x / width : (x + 1) / width - 1;
    }
};
