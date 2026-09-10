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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;
        
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = build(start, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }

        return result;
    }
};
