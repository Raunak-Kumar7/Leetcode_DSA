//cycle exists in directed Graph if Node is 1) Already Visited & 2) IN THE SAME PATH 
    //i.e 2) PATH VISITED (un mark the path visited while going back)
    
    // USING DFS 
    bool dfs(int root, vector<int>& visited, vector<int>& pathVisited, vector<int> adj[])
    {
        //root
        visited[root] = 1;
        pathVisited[root] = 1;
        
        //call children
        for(auto it: adj[root])
        {
            if(!visited[it])
            {
                if(dfs(it,visited,pathVisited,adj)==true)
                    return true;
            }
            //if node has been visited AND from the SAME path --> cycle Found
            else if(pathVisited[it])
                return true;
        }
        pathVisited[root] = 0; //unmark pathVisited
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        //can have cycle in qny component
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,pathVisited,adj)==true) //cycle found
                    return true;
            }
        }
        return false;
    }


    




    //Using BFS. (TOPO SORT) (Indegree array)
    //Apply topo Sort(DAG) --> if N elements in Topo sort --> No cycle
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it2:adj[i])
            {
                indegree[it2]++;
            }
        }
        //Indegree logic already covers all components
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                    {
                        q.push(it);
                    }
                }
                countNodes--;
            }
        }
        return (ans.size()!=V); //!=V means cycle exists --> return true
    }