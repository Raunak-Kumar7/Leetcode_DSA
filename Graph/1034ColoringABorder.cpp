 // 1 component
 //dont color if its surrounded by initial color on all 4 sides
    //using BFS  
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        vector<vector<int>> mat = grid; //color will take place in grid
        
        //we need to work with only 1 component 
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = 1;
        int ele = mat[row][col];
        bool flag = false;
        for(int i=0;i<delrow.size();i++)
        {
            int childR = row + delrow[i];
            int childC = col + delcol[i];
                    
            if((childR>=0 && childR<m && childC>=0 && childC <n) && mat[childR][childC]==ele)
            {
                continue;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
            grid[row][col] = color;
        
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
                    
                    if((childR>=0 && childR<m && childC>=0 && childC <n) && !visited[childR][childC] && mat[childR][childC]==ele)
                    {
                        q.push({childR,childC});
                        visited[childR][childC] = 1;
                        bool flag = false;
                        for(int j=0;j<delrow.size();j++)
                        {
                            int childR2 = childR + delrow[j];
                            int childC2 = childC + delcol[j];

                            if((childR2>=0 && childR2<m && childC2>=0 && childC2 <n) && mat[childR2][childC2]==ele)
                            {
                                continue;
                            }
                            else
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(flag == true)
                            grid[childR][childC] = color;
                        
                    }
                }
                countNodes--;
            }
        }
        return grid;
    }

//can be optimised using only the visited array


// USING DFS
    bool isValid(vector<vector<int>>& grid, int i, int j, int m, int n, vector<int> delrow,vector<int> delcol,int initialc)
    {
        for(int k=0;k<delrow.size();k++)
        {
            int x = i + delrow[k];
            int y = j + delcol[k];
            
            if((x>=0 && x<m && y>=0 && y<n) && grid[x][y]==initialc)
                continue;
            else
                return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n,vector<vector<int>>& visited, vector<int> delrow,vector<int> delcol,int initialc)
    {
        if(isValid(grid,i,j,m,n,delrow,delcol,initialc))
            visited[i][j] = -1; //color
        else
            visited[i][j] = 1; //nocolor
            
        //call children
        for(int k=0;k<delrow.size();k++)
        {
            int childR = i + delrow[k];
            int childC = j + delcol[k];
            
            if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] && grid[childR][childC]==initialc)
            {   
                dfs(grid,childR,childC,m,n,visited,delrow,delcol,initialc);
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        int initialc = grid[row][col];
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        //only 1 component
        dfs(grid,row,col,m,n,visited,delrow,delcol,initialc);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==-1)
                    grid[i][j] = color;
            }
        }
        return grid;
    }