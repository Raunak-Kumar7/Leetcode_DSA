// Recursive Approach
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root== nullptr)
            return new TreeNode(val);
        else if(root->val < val)
        {
            root->right = insertIntoBST(root->right,val);
        }
        else
        {
            root->left = insertIntoBST(root->left,val);
        }
        return root;
    }


//Iterative Approach
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        while(root!=NULL)
        {
            prev = root;
            if(root->val > val) root = root->left;
            else root = root->right;
        }
        if(prev->val < val) prev->right = new TreeNode(val);
        else prev->left = new TreeNode(val);
        
        return temp;
            
    }