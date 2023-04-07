//OR Burn a Tree

//One more approach is to find the diameter of the tree with start as one end of the diameter

//Similar to Print All nodes at a distance K in Binary Tree
    //In this we basically need to find the maximum distance node from the start node
    //Here start is given as int so we need to search it in the BT
    TreeNode* search(TreeNode* root, int target) {
        if (root == NULL || root->val == target) {
            return root;
        }
        
        TreeNode* left = search(root->left, target);
        TreeNode* right = search(root->right, target);
        
        if (left != NULL) {
            return left;
        } else {
            return right;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        //S1: Create map of Parent nodes(undirected graphs)
        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left) mp[n->left] = n;
                if(n->right) mp[n->right] = n;

                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                countNodes--;
            }
        }
        //Parents map ready
        TreeNode* target = search(root,start);
        cout<<target->val;
        //q is empty so reuse it
        unordered_map<TreeNode*, int> visited; //can use bool for better space
        q.push(target);
        visited[target] = 1;
        int dist = 0;
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();

                if(n->left && visited.find(n->left)==visited.end())
                {
                    q.push(n->left);
                    visited[n->left] = 1;
                }
                if(n->right && visited.find(n->right)==visited.end())
                {
                    q.push(n->right);
                    visited[n->right] = 1;
                }
                if(mp[n] && visited.find(mp[n])==visited.end())
                {
                    q.push(mp[n]);
                    visited[mp[n]] = 1;
                }
                countNodes--;
            }
            dist++; //this will execute till there are elements in the queue
        }
        return dist-1; //root is also counted
    }