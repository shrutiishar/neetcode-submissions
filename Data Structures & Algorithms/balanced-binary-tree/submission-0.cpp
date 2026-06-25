class Solution {
public:
    bool flag = true;

    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        int diff = abs(right - left);

        if (diff > 1) {
            flag = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return flag;
    }
};