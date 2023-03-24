//Simple Level Order Traversal
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp; //to store 1 level at a time
        while(!q.empty())
        {
            int countNodes = q.size();
            temp.clear();
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
        }
        return accumulate(temp.begin(),temp.end(),0);
    }


//Simple Level Order Traversal
    //Without Temp array
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {
            int countNodes = q.size();
            sum=0;
            
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                sum+=n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
        }
        return sum;
    }