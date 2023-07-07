void f(TreeNode* root, int val, int i, int depth)
    {
        //add new node
        if(i==depth)
        {
            TreeNode* newNode = new TreeNode(val);
            TreeNode* temp = root->left;
            root->left = newNode;
            newNode->left = temp;
            
            TreeNode* newNode2 = new TreeNode(val);
            temp = root->right;
            root->right = newNode2;
            newNode2->right = temp;
            
        }
        
        //call children
        if(root->left) f(root->left,val,i+1,depth);
        if(root->right) f(root->right, val,i+1,depth);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //normal Traversal
        if(depth==1)
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        f(root,val,1,depth-1);
        return root;
    }