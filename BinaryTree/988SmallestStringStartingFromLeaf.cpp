    //DFS
    void dfs(TreeNode* root, string& curr, string& ans)
    {
        //root
        curr = char(root->val+97) + curr;
        
        //children
        if(root->left) dfs(root->left,curr,ans);
        if(root->right) dfs(root->right,curr,ans);
        
        //Update only when reached leaf
        if(root->left==nullptr && root->right==nullptr && (ans.size()==0 || curr.compare(ans)<0))
            ans = curr;
        curr = curr.substr(1,curr.size()-1);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string curr = "";
        dfs(root,curr,ans);
        return ans;
    }