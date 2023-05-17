int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //first form all the components and store in a vector
        // then check all the element of components should have Component.size()-1 outgoing edges
        //make graph
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]); //undirected edges
        }
        vector<vector<int>> components;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                vector<int> comp;
                q.push(i);
                visited[i] = 1;
                while(!q.empty())
                {
                    int countNodes = q.size();
                    while(countNodes>0)
                    {
                        int node = q.front();
                        q.pop();
                        comp.push_back(node);
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
                components.push_back(comp);
            }
        }
        int l = components.size();
        int ans = 0;
        for(int i=0;i<l;i++)
        {
            int sz = components[i].size();
            bool flag = true;
            for(auto it:components[i])
            {
                if(graph[it].size() != sz-1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }