    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
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
            if(leftToRight!=true)
                reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }