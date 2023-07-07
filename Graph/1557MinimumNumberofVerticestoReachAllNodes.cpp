//Similar to topological sort
    //As the graph is acyclic there will be atleast one node with indegree 0
    //nodes having indegree!=0 can be reached by some other so dont start with them
    //Basically start with nodes having indegree 0 becuase they cant be reached by any other node
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        int e = edges.size();
        for(int i=0;i<e;i++)
        {
            indegree[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) ans.push_back(i);
        }
        return ans;
    }