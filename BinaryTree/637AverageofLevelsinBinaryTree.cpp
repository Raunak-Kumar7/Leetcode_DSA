    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
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
                if(n->left) q.push(n->left); //Always check before inserting
                if(n->right) q.push(n->right);
                countNodes--;
            }
            ans.push_back(accumulate(temp.begin(),temp.end(),0.0)/temp.size()); //sum should be in double(0.0)
        }
       