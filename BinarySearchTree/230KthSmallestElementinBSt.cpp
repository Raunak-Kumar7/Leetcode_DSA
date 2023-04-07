    //Approach 1:
    //Brute Force --> Store inorder(We Can Use Morris Traversal to omit O(n) Stack space)
    void inorder(TreeNode* root,vector<int>& in)
    {
        if(root==nullptr) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        return in[k-1];
    }


    //Approach 2:
    //Better --> Keep a counter instead of storing inorder(We Can Use Morris Traversal to omit O(n) Stack space)
    void inorder(TreeNode* root, int &k,int &ans)
    {
        if(root==nullptr) return;
        inorder(root->left,k,ans);
        k=k-1; // // We have to decrement before checking for root, bcz root is out first element  //  Don't do decrement while passing it in the function bcz its by reference
        if(k==0) 
        {
            ans = root->val;
            return;
        }
        inorder(root->right,k,ans); //decrement happens when we go right
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root,k,ans);
        return ans;
    }

    