//Cycle Detection in Directed Graph
    //Using DFS (stack)
    bool dfs(int root, vector<int>& visited,vector<int>& pathVisited, vector<vector<int>>& graph)
    {
        //root
        visited[root] = 1;
        pathVisited[root] = 1;
        
        //children
        for(auto it:graph[root])
        {
            if(!visited[it])
            {
                if(dfs(it,visited,pathVisited,graph))
                    return true;
            }
            else if(pathVisited[it]) // visisted on the same path
            {
                return true;
            }
        }
        pathVisited[root] = 0; //unmark pathvisited when returning
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        //Create Graph
        int n = numCourses;
        vector<vector<int>> graph(n);
        int p = pre.size();
        for(int i=0;i<p;i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        //cycle may exist in any component
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,pathVisited,graph)) //returns true if cycle exists
                    return false;
            }
        }
        return true;
    }