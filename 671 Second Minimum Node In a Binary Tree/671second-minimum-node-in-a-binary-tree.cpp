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
    int findSecondMinimumValue(TreeNode* root) {
        long long secondMin = LLONG_MAX;
        int minVal = root->val;

        dfs(root, minVal, secondMin);

        return (secondMin == LLONG_MAX) ? -1 : secondMin;
    }

    void dfs(TreeNode* node, int minVal, long long& secondMin) {
        if (!node) return;

        if (node->val > minVal && node->val < secondMin) {
            secondMin = node->val;
        }

        dfs(node->left, minVal, secondMin);
        dfs(node->right, minVal, secondMin);
    }
};
