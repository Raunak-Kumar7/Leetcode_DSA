//Number of Connected Components(4 way connected)
    //Each cell is a node and is represented by {row,col}
    //Using BFS
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r,vector<int> (c,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        int cnt = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;

                    while(!q.empty())
                    {
                        int countNodes = q.size();
                        while(countNodes > 0)
                        {
                            pair<int,int> n = q.front();
                            q.pop();
                            for(int k=0;k<delrow.size();k++)
                            {
                                //children should satisfy 3 conditions
                                int childR = n.first + delrow[k];
                                int childC = n.second + delcol[k];
                                if((childR >= 0 && childR < r && childC >= 0 && childC < c) && !visited[childR][childC] && grid[childR][childC]=='1')
                                {
                                    q.push({childR,childC});
                                    visited[childR][childC] = 1; //mark visited while pushing in queue
                                }
                            }
                            countNodes--;
                        }
                    }
                }
            }
        }
        return cnt;
    }





//Using DFS(Recursion)
    void dfs(vector<vector<char>>& grid,int m, int n, vector<vector<int>>& visited, vector<int> delrow, vector<int> delcol, int r, int c )
    {
        //Root
        visited[r][c] = 1;

        //call children
        for(int i=0;i<delrow.size();i++)
        {
            int childR = r + delrow[i];
            int childC = c + delcol[i];
            //should meet 3 conditions
            if((childR >= 0 && childR < m && childC >= 0 && childC < n) && !visited[childR][childC] && grid[childR][childC]=='1')
            {
                dfs(grid,m,n,visited,delrow,delcol,childR,childC);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(grid,m,n,visited,delrow,delcol,i,j);
                }
            }
        }
        return cnt;
    }