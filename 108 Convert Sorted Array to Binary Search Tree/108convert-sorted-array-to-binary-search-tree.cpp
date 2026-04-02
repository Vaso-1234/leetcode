/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;

        int n = nums.size();
        int mid = (0 + n - 1) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, n - 1});

        while(!q.empty()) {
            auto [node, left, right] = q.front();
            q.pop();

            int m = (left + right) / 2;

            if(left <= m - 1) {
                int lmid = (left + (m - 1)) / 2;
                node->left = new TreeNode(nums[lmid]);
                q.push({node->left, left, m - 1});
            }

            if(m + 1 <= right) {
                int rmid = ((m + 1) + right) / 2;
                node->right = new TreeNode(nums[rmid]);
                q.push({node->right, m + 1, right});
            }
        }

        return root;
    }
};