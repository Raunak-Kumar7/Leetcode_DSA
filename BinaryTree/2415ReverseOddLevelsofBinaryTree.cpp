//Approach 1: Store the level order traversal level wise in a 2d vector
    //Then again do level order traversal and when level is odd update the nodes values
    //T.C O(2n) S.C. O(n)
    
    //Approach 2: As we complete a level if level is odd again do that level and fill the values in reverse
    //T.C. O(2n) not exactly 2n because we will traverse only the odd levels twice
    //S.C. O(Max Nodes in a level) O(n/2)
    TreeNode* reverseOddLevels(TreeNode* root) {
        //Approach 1
        if(root==nullptr) return nullptr;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int countNodes = q.size();
            vector<int> temp;
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                temp.push_back(n->val);
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
            ans.push_back(temp);
        }
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int countNodes = q.size();
            int i=ans[level].size()-1;
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                if(level%2==1)
                {
                    n->val = ans[level][i--];
                }
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
            level++;
        }
        return root;
    }