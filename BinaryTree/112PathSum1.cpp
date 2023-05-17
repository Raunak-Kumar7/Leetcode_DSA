    //DFS
    //Similar to 129
    bool dfs(TreeNode* root, int& sum, int targetSum)
    {
        //root
        if(root==nullptr) return false;
        sum+=root->val;
        
        //children
        if(root->left) if(dfs(root->left,sum,targetSum)) return true;
        if(root->right) if(dfs(root->right,sum,targetSum)) return true;
        
        //check at leaf only
        if(root->left==nullptr && root->right==nullptr)
        {
            if(sum==targetSum) return true;
        }
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return dfs(root,sum,targetSum);
    }