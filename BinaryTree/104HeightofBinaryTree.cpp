    //Approach 1: DFS (Recursive PostorderType)
    //T.C. O(n) travel all nodes
    //S.C. O(n) W.C. Skewed Tree  Average O(log2n)
    // 1.Find lh
    // 2.Find rh
    // 3.Apply 1+max(lh+rh)
    
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh,rh);
    }




    //Approach 2: BFS(Level Order Traversal)
    //Extra Space O(N) queue But no recursive stack
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int h = 0;
        while(!q.empty())
        {
            int countNodes = q.size();
            h++;
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
        }
        return h;
    }