    TreeNode* search(TreeNode* root, int target) {
        if (root == NULL || root->val == target) {
            return root;
        }
        
        TreeNode* left = search(root->left, target);
        TreeNode* right = search(root->right, target);
        
        if (left != NULL) {
            return left;
        } else {
            return right;
        }
    }