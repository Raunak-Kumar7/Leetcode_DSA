//S1-- check if not already colored --> color with opposite of parent and push in queue
    //           else if colored --> just confirm if its opposite of parent color
    // Using BFS
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colored(V,-1); //-1 not colored 0 --> color1   1 --> color2
        //input is similar to adjacency list
        
        //can have multiple componenets (some component may not be bipartite)
        for(int i=0;i<V;i++)
        {
            if(colored[i]==-1) //not visited
            {
                queue<int> q;
                q.push(i);
                colored[i] = 0; //color while pushing in queue
                while(!q.empty())
                {
                    int countNodes = q.size();
                    while(countNodes>0)
                    {
                        int node = q.front();
                        q.pop();
                        
                        for(int j = 0;j<graph[node].size();j++)
                        {
                            int child = graph[node][j];
                            if(colored[child]!=-1) //already colored child
                            {
                                if(colored[child]==colored[node])
                                    return false;
                            }
                            else //not colored --> color with opposite of parent
                            {
                                colored[child] = colored[node]==0 ? 1: 0;
                                q.push(child);
                            }
                        }
                        countNodes--;
                    }
                }
            }
        }
        return true;
    }



    //using DFS
    bool dfs(int root, int color, vector<int>& colored, vector<vector<int>>& graph)
    {
        //parent
        if(colored[root]==-1)
            colored[root] = color;
        
        //call children
        for(int i=0;i<graph[root].size();i++)
        {
            int child = graph[root][i];
            if(colored[child]!=-1) //already colored
            {
                if(colored[child]==color) 
                    return false;
            }
            else
            {
                if(!dfs(child,!color,colored,graph)) return false;
            }
        }
        return true; //no violation found in bw
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colored(V,-1);
        
        //can have multiple componenets
        for(int i=0;i<V;i++)
        {
            if(colored[i]==-1) //not visited
            {
                if(!dfs(i,0,colored,graph)) return false;
            }
        }
        for(auto i:colored) cout<<i<<" ";
        return true;
    }