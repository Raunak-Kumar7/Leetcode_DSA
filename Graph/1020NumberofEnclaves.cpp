//Observations: any component having a 1 on the boundary, that entire component will walk off
    //so we need to mark those visited which components are on boundary(Sources which lie on boundary), rest will be locked

    //Using BFS
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};

        //Travelling boundary and collecting sources(multisource BFS)
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(((i==0||i==m-1) || (j==0||j==n-1)) && grid[i][j] == 1)
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                pair<int,int> node = q.front();
                q.pop();
                
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    
                    //satisfy 3 conditions
                    if((childR >= 0 && childR < m && childC>=0 && childC< n) && !visited[childR][childC] && grid[childR][childC] == 1)
                    {
                        q.push({childR,childC});
                        visited[childR][childC] = 1;
                    }
                }
                countNodes--;
            }
        }
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }



    //using dfs
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n, vector<vector<int>>& visited,vector<int> delrow,vector<int> delcol)
    {
        //root
        visited[r][c] = 1;
        
        //calling children
        for(int i=0;i<delrow.size();i++)
        {
            int childR = r + delrow[i];
            int childC = c + delcol[i];
            
            if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] && grid[childR][childC] == 1)
            {
                dfs(grid,childR,childC,m,n,visited,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        
        //marking components having 1 on boundary
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||i==m-1||j==0||j==n-1) && grid[i][j]==1)
                {
                    dfs(grid,i,j,m,n,visited,delrow,delcol);
                }
            }
        }
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                    count++;
            }
        }
        return count;
        
    }