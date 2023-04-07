//Using Level Order Traversal and picking the last node in each level
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int countNodes = q.size();
            int x = countNodes; //to compare the last node
            int i=0;
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                if(i==x-1) //both will 
                    ans.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
                i++;
            }
        }
        return ans;
    }