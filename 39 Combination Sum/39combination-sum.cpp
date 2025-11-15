class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int start) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], curr, i); // reuse allowed
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, curr, 0);
        return res;
    }
};
