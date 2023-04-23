// Using BFS
    //each cell is represented as a node {i,j}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // find maximum 1s in a component
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        int maxi = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    int tempans = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    tempans++;
                    visited[i][j] = 1;
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
                                
                                //should satisfy 3 conditions
                                if((childR >=0 && childR <m && childC >= 0 && childC <n) && !visited[childR][childC] && grid[childR][childC]==1)
                                {
                                    q.push({childR,childC});
                                    tempans++;
                                    visited[childR][childC] = 1;
                                }
                            }
                            countNodes--;
                        }
                    }
                    maxi = max(maxi,tempans);
                }
            }
        }
        return maxi;
    }



// Using DFS
    // Finding component with max 1s
    void dfs(int i, int j, int m , int n, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int> delrow, vector<int> delcol,int& tempans)
    {
        //root
        visited[i][j] = 1;
        tempans++;

        //children call
        for(int k=0;k<delrow.size();k++)
        {
            int childR = i + delrow[k];
            int childC = j + delcol[k];

            //satisfy 3 conditions
            if((childR >=0 && childR <m && childC >= 0 && childC < n) && !visited[childR][childC] && grid[childR][childC]==1)
            {
                dfs(childR,childC,m,n,grid,visited,delrow,delcol,tempans);
            }
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        int maxi = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tempans = 0;
                if(!visited[i][j] && grid[i][j]==1)
                {
                    dfs(i,j,m,n,grid,visited,delrow,delcol,tempans);
                    maxi = max(maxi,tempans);
                }
            }
        }
        return maxi;
    }