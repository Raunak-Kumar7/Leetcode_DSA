//Bottom up (but still left to right)

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int countNodes = q.size();
            vector<int> temp;
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }