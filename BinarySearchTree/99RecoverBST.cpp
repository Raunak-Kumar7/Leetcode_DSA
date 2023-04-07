    //Exactly 2 nodes are swapped
    
    //Method 1: Brute Force: Store the Inorder Traversal and sort it and again do the inorder traversal and overwrite where the value is not same
    void inorder(vector<int>& in, TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(in,root->left);
        in.push_back(root->val);
        inorder(in,root->right);
    }
    void update(int &idx, vector<int>& in, TreeNode* root)
    {
        if(root==nullptr)
            return;
        update(idx,in,root->left);
        if(in[idx]!=root->val) root->val = in[idx];
        idx = idx+1; //while passing by refernce dont change value inside function passing
        update(idx,in,root->right);
    }
    void recoverTree(TreeNode* root) {
        vector<int> in;
        inorder(in,root);
        sort(in.begin(),in.end());
        for(auto i: in)
            cout<<i<<" ";
        int idx = 0;
        update(idx,in,root); //can not directly pass 0 as it is by refernce, so we need to create a memory(i.e.) variable bcz we are sending a memory location 
    }