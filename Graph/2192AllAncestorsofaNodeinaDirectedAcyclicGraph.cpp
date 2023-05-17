    // (no need of visited array in topo sort bfs only INDEGREE ARRAY)
    //Topological Sort
    //using BFS
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //S1: Create Graph
        vector<vector<int>> graph(n);
        int e = edges.size();
        for(int i=0;i<e;i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> visited(n,0);
        vector<int> indegree(n,0);
        vector<set<int>> ans(n); //ancestor array// filled in topo sort order
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        //push nodes with indegree 0
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                int node = q.front();
                q.pop();
                for(auto it:graph[node])
                {
                    indegree[it]--; //even if its not 0 still we have a parent and its ancestors
                    ans[it].insert(node); //parent
                    for(auto it2:ans[node])
                    {
                        ans[it].insert(it2); //ancestors
                    }
                    if(indegree[it]==0 && !visited[it])
                    {
                        visited[it] = 1;
                        q.push(it);
                    }
                }
                countNodes--;
            }
        }
        vector<vector<int>> ans2(n); 
        for(int i=0;i<n;i++)
        {
            for(auto it2:ans[i])
            {
                ans2[i].push_back(it2);
            }
        }
        return ans2;
    }



///USING DFS (DO)