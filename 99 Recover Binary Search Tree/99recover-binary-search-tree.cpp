class Solution {
public:
    TreeNode *first = NULL, *second = NULL, *prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        if (prev->val > root->val) {
            if (!first) first = prev;   
            second = root;             
        }

        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
