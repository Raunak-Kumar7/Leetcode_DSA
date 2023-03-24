//Simalar to max height
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(!root->left && !root->right) return 1; //no child --> return 1 to count the node itself
        int lh = 1e5, rh = 1e5;                //Maximum number of nodes 10^5 --> worst case skewed tree
        if(root->left) lh = minDepth(root->left);
        if(root->right) rh = minDepth(root->right);
        return 1 + min(lh,rh);
    }