//Using BFS
    /// if we are about to visit a visited node *which is not a parent* then it means cycle exists
    // for this we need to carry the {node, parent} in the queue
    //We also need to check for a cycle in all the components
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++) //For disconnected components
        {
            if(!visited[i])
            {
                queue<pair<int,int>> q;
                q.push({i,-1}); //put -1 as parent for first node
                visited[i] = 1;
                while(!q.empty())
                {
                    int countNodes = q.size();
                    while(countNodes > 0)
                    {
                        pair<int,int> p = q.front();
                        q.pop();
                        int node = p.first;
                        int parent = p.second;
                        for(auto it:adj[node])
                        {
                            if(it!=parent && !visited[it])
                            {
                                q.push({it,node});
                                visited[it] = 1;
                            }
                            else if(it==parent)
                                continue;
                            else
                                return 1; //cycle exists
                        }
                        countNodes--;
                    }
                }
            }
        }
        return 0; //no cycle found;
    }



// Function to detect cycle in an undirected graph.
    // Using DFS
    // need to maintain parent node
    bool dfs(int root,int parent, vector<int> adj[], vector<int>& visited)
    {
        //root
        visited[root] = 1;
        
        //call children
        for(auto i:adj[root])
        {
            if(i!=parent && !visited[i])
            {
                if(dfs(i,root,adj,visited))
                    return true;
            }
            else if(i!=parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        //cycle can exist in any of the components
        bool ans = false;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                ans = (ans||dfs(i,-1,adj,visited));
        }
        return ans;
    }