    //Reverse the question structure
    //Create a tree like graph and then apply maximum path sum from root to leaf
    //only if they have children they will add the inform time
    //using dfs
    void dfs(int root, int& ans, int& maxi, vector<int>& manager, vector<int>& informTime,vector<vector<int>>& graph)
    {
        //root
        if(graph[root].size()>0)
            ans+=informTime[root];
        //children
        for(auto it:graph[root])
        {
            dfs(it,ans,maxi,manager,informTime,graph);
        }
        maxi = max(maxi,ans);
        ans-=informTime[root];
        return ;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                graph[manager[i]].push_back(i);
            }
        }
        int maxi = INT_MIN;
        int ans = 0;
        dfs(headID,ans,maxi,manager,informTime,graph);
        return maxi;   
    }