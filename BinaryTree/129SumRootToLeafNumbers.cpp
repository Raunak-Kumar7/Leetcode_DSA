    //DFS 
    //Similar to 1376
    //Create numbers and them keep adding 
    //remove before leaving
    void dfs(TreeNode* root, int& ans, int& num)
    {
        //root
        num = num*10 + root->val;
        
        //children
        if(root->left) dfs(root->left,ans,num);
        if(root->right) dfs(root->right,ans,num);
        
        //We only need to add if its a leaf node
        if(root->left==nullptr && root->right==nullptr)
            ans+=num;
        num/=10; //remove last digit (NUMBER CREATION OPERATES NORMALLY)
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int num = 0;
        dfs(root,ans,num);
        return ans;
    }