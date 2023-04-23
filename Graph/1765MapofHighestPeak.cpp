//Water --> 1, Land --> 0
    //All water cells must be given height 0, 
    //Multi source BFS with distance from water cells
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<vector<int>> dist(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        
        queue<pair<pair<int,int>, int>> q;
        //Push all sources in the queue
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
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
            while(countNodes > 0)
            {
                pair<int,int> node = q.front().first;
                int d = q.front().second;
                q.pop();
                
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    
                    if((childR>=0 && childR<m && childC >=0 && childC<n) && !visited[childR][childC] && grid[childR][childC]==0) //should be land becuase all sources(water) were already initially pushed
                    {
                        q.push({{childR,childC},d+1});
                        dist[childR][childC] = d+1;
                        visited[childR][childC] = 1;
                    }
                }
                countNodes--;
            }
        }
        return dist;
    }