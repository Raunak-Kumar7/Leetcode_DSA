    //Like (Pre,In,Post) Order Traversals
    
    //Recursive + visited array
    void dfs(vector<int> adj[], vector<int>& visited, vector<int>& ans, int root)
    {
        //root operation
        ans.push_back(root);
        visited[root] = 1;
        
        //recursion call to children
        for(auto it: adj[root])
        {
            if(!visited[it])
                dfs(adj,visited,ans,it);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0); //0 based indexing
        vector<int> ans;
        
        dfs(adj,visited,ans,0);
        return ans;
    }


// DFS for Disconnected Graphs
    //Recursive + visited array
    void dfs(vector<int> adj[], vector<int>& visited, vector<int>& ans, int root)
    {
        //root operation
        ans.push_back(root);
        visited[root] = 1;
        
        //recursion call to children
        for(auto it: adj[root])
        {
            if(!visited[it])
                dfs(adj,visited,ans,it);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0); //0 based indexing
        vector<int> ans;
        for(int i=0;i<V;i++) //To handle Disconnected graphs
        {
            if(!visited[i])
                dfs(adj,visited,ans,i);
        }
        return ans;
    }