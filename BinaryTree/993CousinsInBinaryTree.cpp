// Approach 1 //Can store each level in a temp array with 0s separating cousins
    
    //Finding cousins in level order traversal
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  //to separate sibilings
        while(!q.empty())
        {
            int countNodes = q.size();
            vector<int> temp;
            while(countNodes > 0)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n==nullptr)
                {
                    temp.push_back(0);
                    countNodes--;
                    continue;
                }
                temp.push_back(n->val);
                
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                q.push(nullptr);
                countNodes--;
            }
            int idx = -1;
            int idy = -1;
            int zeros = 0;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]==x) idx = i;
                if(temp[i]==y) idy = i;
            }
            if(idx!=-1 && idy!=-1)
            {
                for(int i= min(idx,idy); i<=max(idx,idy);i++)
                {
                    if(temp[i]==0) zeros++;
                }
            }
            if(idx!=-1 && idy!=-1 && zeros > 0) //zeros exist between 2 --> not siblings + are in same level
                return true;
        }
        return false;
    }