/// OR  -------Number of connected components in a graph------


//Adjacency Matrix Representation

//Number of Connected Components
    //Just need to keep a counter in BFS/DFS
    //Using BFS:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //graph is in the form of adjacency matrix
        int v = isConnected.size();
        vector<int> visited(v,0); //1 based indexing (adjusted by -1)
        int cnt = 0;
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                cnt++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
        
                while(!q.empty())
                {
                    int countNodes = q.size();
                    while(countNodes>0)
                    {
                        int n = q.front();
                        q.pop();
                        for(int i =0;i<v;i++)
                        {
                            if(isConnected[n][i]==1)
                            {
                                if(!visited[i])
                                {
                                    q.push(i);
                                    visited[i] = 1;
                                }
                            } 
                        }
                        countNodes--;
                    }
                } 
            }
        }
        return cnt;
    }


//Using DFS
    void dfs(vector<vector<int>>& isConnected, int v, vector<int>& visited, int root)
    {
        //root
        visited[root] = 1;

        //call for children
        for(int i=0;i<v;i++)
        {
            if(isConnected[root][i]==1 && !visited[i])
            {
                dfs(isConnected, v, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int cnt = 0;
        vector<int> visited(v,0);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(isConnected, v, visited,i);
            }
        }
        return cnt;
    }