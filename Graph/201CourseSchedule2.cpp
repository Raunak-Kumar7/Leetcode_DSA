//Return the order --if no cycle exists --> Topo Sort
    //Using DFS(push root in stack)(visited+pathVisited)
    bool dfs(int root, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& graph, stack<int>& st)
    {
        //root
        visited[root] = 1;
        pathVisited[root] = 1;
        
        
        //children
        for(auto it:graph[root])
        {
            if(!visited[it])
            {
                if(dfs(it,visited,pathVisited,graph,st))
                    return true;
            }
            if(pathVisited[it]) //visited on the same path
                return true;
        }
        st.push(root); //WHEN RETURNING (i.e. coming upwards)
        pathVisited[root] = 0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre)     {
        int n = numCourses;
        vector<vector<int>> graph(n);
        //create Graph
        int p = pre.size();
        for(int i=0;i<p;i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        //for all components
        vector<int> ans;
        stack<int> st;
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                if(dfs(i,visited,pathVisited,graph,st))
                    return {};
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }



//USING BFS