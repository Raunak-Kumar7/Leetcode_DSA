    //it is post order traversal because first we need to reach the left most and right most nodes then swap
    void postorder(TreeNode* root)
    {  
        if(root==nullptr) return;
        postorder(root->left);
        postorder(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    
    } 
    TreeNode* invertTree(TreeNode* root) {
        postorder(root);
        return root;
    }