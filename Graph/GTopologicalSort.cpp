//Using DFS   (VISITED Array  + STACK to store topo sort)
	//push in stack when returning so that element at the top of the tree will be pushed at LAST and will be at the top of stack and first of topo sort
	void dfs(int root, vector<int>& visited, vector<int> adj[], stack<int>& st)
	{
	    //root
	    
	    visited[root] = 1;
	    
	    //children
	    for(auto it:adj[root])
	    {
	        if(!visited[it])
	        {
	            dfs(it,visited,adj,st);
	        }
	    }
	    st.push(root); //push in stack when returning
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    stack<int> st;
	    //for all components;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	            dfs(i,visited,adj,st);
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}


/////NO NEED OF VISITED ARRAY --> Only INDEGREE ARRAY 
	//Using BFS (Kahn's Algorithm)(Only INDEGREE Array)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    vector<int> ans;
	    //make indegree array
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    //push all nodes with indegree 0 --> so we dont need to write for all components
	    //as nodes with indegree 0 will be there in all componenets( all DAG)
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int countNodes = q.size();
	        while(countNodes > 0)
	        {
	            int node = q.front();
	            q.pop();
	            ans.push_back(node);
	            for(auto it:adj[node])
	            {//decrement indegree of children if its 0 add to queue
	                indegree[it]--;
	                if(indegree[it]==0 )
	                {
	                    q.push(it);
	                }
	            }
	            countNodes--;
	        }
	    }
	    return ans;
	}   