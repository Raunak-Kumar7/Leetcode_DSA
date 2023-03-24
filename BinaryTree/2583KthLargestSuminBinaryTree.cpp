vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        q.push(root);
        while(!q.empty())
        {
            int nodeCount =q.size();
            vector<int> t;
            while(nodeCount>0)
            {
                TreeNode* temp = q.front();
                q.pop();
                t.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                nodeCount--;
            }
            ans.push_back(t);
        }
        return ans;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<int>> ans;
        ans = levelOrder(root);
        int n = ans.size();
        priority_queue<long long ,vector<long long >, greater<long long> > pq;
        for(int i=0;i<n;i++)
        {
            int x = ans[i].size();
            long long sum = 0;
            for(int j=0;j<x;j++)
            {
                sum+=ans[i][j];
            }
            pq.push(sum);
            if(pq.size()>k)
                pq.pop();
        }
        if(pq.size()<k) ///We need to check if there exists k sums of or not i.e. if levels are lesser than k then kth largest sum doesnt exist
            return -1;
        return pq.top();
    }