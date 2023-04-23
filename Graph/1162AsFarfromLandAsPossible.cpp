//from all land cells and keep a distance variable and mark all nearby water cells with dist
    //Multisource BFS from all land cells
    //Using BFS (Maximize/ Minimize distance --> use BFS)
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        vector<vector<int>> dist(n,vector<int> (n,0));
        
        //push all sources(lands) in the queue
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                pair<int,int> node = q.front().first;
                int d = q.front().second;
                q.pop();
                
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    
                    if((childR >=0 && childR <n && childC >=0 && childC<n) && !visited[childR][childC] && grid[childR][childC]==0) //water
                    {
                        q.push({{childR,childC},d+1});
                        visited[childR][childC] = 1;
                        dist[childR][childC] = d+1;
                    }
                }
                countNodes--;
            }
        }
        //dist matrix will be all 0 when
        // 1) All are land
        // 2) All are water so queue is always empty
        int maxi = 0;
        for(auto i:dist)
        {
            for(auto j:i)
                maxi = max(maxi,j);
        }
        if(maxi==0) return -1;
        return maxi;
    }