    //S1: Make Map of parent nodes(Undirected graph) using BFS (level order traversal)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> mp; //Format : {node,parent}
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
        //Map of parents created, Now we can move up as well as down

        //Now we do BFS traversal to find nodes at dist k in an undirected graph from target(search if target is int)
        //q is already empty so we use it
        while(!q.empty()) q.pop(); /// no use of this
        unordered_map<TreeNode*,int> visited; //so that we dont push the already checked node(i.e. we only move away from the target)
        /// IMPORTANT Mark a node visited WHEN WE INSERT IT IN QUEUE
        vector<int> ans;

        q.push(target); //Start from target
        visited[target] = 1;
        int dist = 0;
        while(!q.empty()) 
        {
            if(dist==k) break;
            int countNodes = q.size();
            while(countNodes>0)
            {
                TreeNode* n = q.front();
                q.pop();
                
                if(n->left && visited.find(n->left)==visited.end())
                {
                    q.push(n->left); //move left
                    visited[n->left] = 1; //*Mark during inserting in queue*
                }
                if(n->right && visited.find(n->right)==visited.end())
                {
                    q.push(n->right); //move right
                    visited[n->right] = 1;
                } 
                if(mp.find(n)!=mp.end() && visited.find(mp[n])==visited.end())
                {
                    q.push(mp[n]); //move to parent
                    visited[mp[n]] = 1;
                } 
                countNodes--;
            }
            dist++; //increment dist
        }
        //All the remaining elements in queue are at distance k
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }