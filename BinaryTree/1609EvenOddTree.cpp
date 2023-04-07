//Level Order Traversal O(n) space only using queue
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int countNodes = q.size();
            int prev = q.front()->val;
            int cnt = 0; //temp variable as idx in a level
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                if(level%2==0)//even level node
                {
                    if(n->val%2==0)
                        return false;
                    if(cnt!=0)
                    {
                        if(n->val <= prev)
                            return false;
                        prev = n->val;
                    }
                    cnt++;
                }
                else
                {
                    if(n->val%2==1)
                        return false;
                    if(cnt!=0)
                    {
                        if(n-> val >= prev)
                            return false;
                        prev = n->val;
                    }
                    cnt++;
                }
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
            level++;
        }
        return true;
    }