int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        if(root==nullptr) return ans;
        q.push(root);
        int maxsum=INT_MIN;
        int i=0;
        while(!q.empty())
        {
            int nodeCount =q.size();
            int sum=0;
            i++;
            while(nodeCount>0)
            {
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                nodeCount--;
            }
            if(sum>maxsum)
            {
                maxsum=sum;
                ans=i;
            }
        }
        return ans;
    }

//Done without using temp array, instead directly taking sum and taking max from it



int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        //minimum no of nodes = 1--> root can not be null
        q.push(root);
        vector<int> temp;
        while(!q.empty())
        {
            int nodeCount =q.size();
            int sum=0;
            while(nodeCount>0)
            {
                TreeNode* n = q.front();
                q.pop();
                sum+=n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                nodeCount--;
            }
            temp.push_back(sum);
        }
        return (max_element(temp.begin(),temp.end()) - temp.begin()) + 1;
    }
    //using temp array Space O(height) log2N