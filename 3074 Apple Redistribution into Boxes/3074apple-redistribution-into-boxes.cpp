class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        long long currCapacity = 0;
        int boxes = 0;

        for (int cap : capacity) {
            currCapacity += cap;
            boxes++;
            if (currCapacity >= totalApples) {
                return boxes;
            }
        }

        return boxes; 
    }
};
