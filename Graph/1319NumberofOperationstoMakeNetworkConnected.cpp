//Using BFS
//Minimum Number of edges for a graph to be connected is n-1
    //if  n-1 edges are there it is possible ( ans = number of components-1.  to connect a component require 1 edge)
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(n-1>edges)
            return -1;
        
        vector<int> visited(n,0);
        //make a graph
        vector<vector<int>> graph(n);
        for(auto i:connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        int components = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                components++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty())
                {
                    int countNodes = q.size();
                    while(countNodes > 0)
                    {
                        int node = q.front();
                        q.pop();
                        for(auto it:graph[node])
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
        return components-1;
    }