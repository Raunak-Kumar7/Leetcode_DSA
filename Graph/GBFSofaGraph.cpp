//Similar to Level Order Traversal
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<int> visited(V,0); //0 based indexing
        queue<int> q;
        q.push(0); //starting node
        visited[0] = 1; //mark starting node as visited
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                int n = q.front();
                q.pop();
                ans.push_back(n);
                for(auto it:adj[n])
                {
                    if(!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
                countNodes--;
            }
        }
        return ans;
    }



// BFS for Disconnected Graphs

//Similar to Level Order Traversal
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<int> visited(V,0); //0 based indexing
        for(int i=0;i<V;i++) //To make sure it works for all graphs(including disconnected)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i); //starting node
                visited[i] = 1; //mark starting node as visited
                while(!q.empty())
                {
                    int countNodes = q.size();
                    while(countNodes > 0)
                    {
                        int n = q.front();
                        q.pop();
                        ans.push_back(n);
                        for(auto it:adj[n])
                        {
                            if(!visited[it])
                            {
                                q.push(it);
                                visited[it] = 1;
                            }
                        }
                        countNodes--;
                    }
                }
            
            }
        }
        
        return ans;
    }