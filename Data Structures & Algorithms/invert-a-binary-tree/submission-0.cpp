class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;

        // Swap left and right children
        swap(root->left, root->right);

        // Recursively invert both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};