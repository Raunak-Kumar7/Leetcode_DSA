vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty())
        {
            int countNodes = q.size();
            vector<int> temp;
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n==nullptr)
                {
                    temp.push_back(0); //coousins are separated by a 0
                    countNodes--;
                    continue;
                }
                temp.push_back(n->val);
                if(n->left) q.push(n->left); //Always check before inserting
                if(n->right) q.push(n->right);
                q.push(nullptr);
                countNodes--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void levelOrder2(TreeNode* root,vector<vector<int>>& ans) {
        if(root==nullptr) return ;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        int j=0;
        while(!q.empty())
        {
            int countNodes = q.size();
            
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                n->val = ans[i][j];
                j++;
                if(n->left) q.push(n->left); //Always check before inserting
                if(n->right) q.push(n->right);
                countNodes--;
            }
            i++;
            j=0;
        }
        return ;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<vector<int>> ans = levelOrder(root);
        vector<int> levelsum;
        for(auto i:ans)
        {
            int sum = 0;
            for(auto j:i)
            {
                sum+=j;
            }
            levelsum.push_back(sum);
        }
        vector<vector<int>> ans2;
        for(int i=0;i<ans.size();i++)
        {
            int temp =0;
            int cnt = 0;
            vector<int> t;
            for(int j=0;j<ans[i].size();j++)
            {
                if(ans[i][j]!=0)
                {
                    temp+=ans[i][j];
                    cnt++;
                }
                else{
                    while(cnt>0)
                    {
                        ans[i][j-cnt] = levelsum[i] - temp;
                        t.push_back(ans[i][j-cnt]);
                        cnt--;
                    }
                    temp = 0;
                }
            }
            ans2.push_back(t);
        }
        for(auto i:ans2)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        levelOrder2(root,ans2);
        return root;
    }