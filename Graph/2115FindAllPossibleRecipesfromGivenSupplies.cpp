    //Topo Sort
    //Using BFS(kahn's Algo) --> indegree array
    //Initial States with indegree 0 ----> SUPPLIES
    // We need to check which RECIPES states are reachable
    //INGRIDENTS are basically edges
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //creating map to convert string to int
        int idx = 0;
        unordered_map<string,int> mp;
        for(auto it:recipes)
        {
            if(mp.find(it)==mp.end()) //not exists
            {
                mp[it] = idx;
                idx++;
            }
        }
        for(auto it2:ingredients)
        {
            for(auto it:it2)
            {
                if(mp.find(it)==mp.end()) //not exists
                {
                    mp[it] = idx;
                    idx++;
                }
            }
        }
        for(auto it:supplies)
        {
            if(mp.find(it)==mp.end()) //not exists
            {
                mp[it] = idx;
                idx++;
            }
        }
        
        int V = mp.size();
        vector<vector<int>> graph(V);
        for(int i=0;i<ingredients.size();i++)
        {
            for(auto it:ingredients[i])
            {
                graph[mp[it]].push_back(mp[recipes[i]]);
            }
        }
        //graph is ready
        vector<int> indegree(V);
        for(auto it:graph)
        {
            for(auto it2:it)
                indegree[it2]++;
        }
        queue<int> q;
        for(auto it:supplies) //or push with indegree 0
        {
            q.push(mp[it]); //indegree already 0
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                int node = q.front();
                q.pop();
                for(auto it:graph[node])
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
        vector<string> ans;
        //now check if indegree of which recipies = 0
        for(auto it: recipes)
        {
            if(indegree[mp[it]]==0)
                ans.push_back(it);
        }
        return ans;
    }




//DO dfs