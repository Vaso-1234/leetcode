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
    unordered_map<int, int> indexMap;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;
        for (int i = 0; i < n; i++) {
            indexMap[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {
        if (left > right) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = indexMap[rootVal];
        root->right = build(inorder, postorder, mid + 1, right);
        root->left  = build(inorder, postorder, left, mid - 1);

        return root;
    }
};
