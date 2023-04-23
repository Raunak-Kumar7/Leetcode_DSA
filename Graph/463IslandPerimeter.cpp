//perimeter adds number of times a cell has water around it

//Using BFS
    int islandPerimeter(vector<vector<int>>& grid) {
        //exactly 1 island is given
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};

        int perimeter = 0;
        bool flag = false;
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    flag = true; //component found
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;

                    while(!q.empty())
                    {
                        int countNodes = q.size();
                        while(countNodes > 0)
                        {
                            pair<int,int> node = q.front();
                            q.pop();
                            int landsAroundMe = 0;
                            for(int i=0;i<delrow.size();i++)
                            {
                                int nR = node.first + delrow[i];
                                int nC = node.second + delcol[i];
                                if(nR >= 0 && nR < m && nC >= 0 && nC < n && grid[nR][nC]==1)
                                {
                                    landsAroundMe++;
                                }
                            }
                            perimeter += (4 - landsAroundMe);
                            // cout<<node.first<<" "<<node.second<<"    "<<perimeter<<endl;
                            for(int i=0;i<delrow.size();i++)
                            {
                                int neighborR = node.first + delrow[i];
                                int neighborC = node.second + delcol[i];
                                
                                if(neighborR >= 0 && neighborR < m &&neighborC >= 0 && neighborC < n && grid[neighborR][neighborC]==1 && !visited[neighborR][neighborC] && grid[neighborR][neighborC]==1)
                                {
                                    q.push({neighborR,neighborC});
                                    visited[neighborR][neighborC] = 1;
                                }
                            }
                            countNodes--;
                        }
                    }
                    break; //breaking becuase only 1 component was given
                }
            }
            if(flag==true) break;
        }
        return perimeter;
    }




    //Perimeter = sum of number of water around all lands
    //Using DFS
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int> delrow, vector<int> delcol, int r, int c, int m, int n , int& perimeter)
    {
        //root
        visited[r][c] = 1;
        int landsAroundMe = 0;
        for(int i=0;i<delrow.size();i++)
        {
            int neighborR = r + delrow[i];
            int neighborC = c + delcol[i];

            if(neighborR >=0 && neighborR <m && neighborC >=0 && neighborC <n && grid[neighborR][neighborC]==1)
            {
                landsAroundMe++;
            }
        }
        perimeter+= (4-landsAroundMe);

        //call Children
        for(int i=0;i<delrow.size();i++)
        {
            int neighborR = r + delrow[i];
            int neighborC = c + delcol[i];

            if(neighborR >=0 && neighborR <m && neighborC >=0 && neighborC <n && grid[neighborR][neighborC]==1 && !visited[neighborR][neighborC])
            {
                dfs(grid,visited,delrow,delcol,neighborR,neighborC,m,n,perimeter);
            }
        }

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        int perimeter = 0;
        bool flag = false; //only 1 component
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    dfs(grid,visited,delrow,delcol,i,j,m,n,perimeter);
                    flag = true;
                    break;
                }
                
            }
            if(flag==true) break;
        }
        return perimeter;

    }