//LC 694

//Store different island shaped is set (SUBTRACT BASE FROM EACH ISLAND)
  //Using BFS
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        //need to go to all the components
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    int baseX = i;
                    int baseY = j;
                    vector<pair<int,int>> temp;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    temp.push_back({i-baseX,j-baseY});
                    while(!q.empty())
                    {
                        int countNodes = q.size();
                        while(countNodes > 0)
                        {
                            pair<int,int> node = q.front();
                            q.pop();
                            
                            for(int k=0;k<delrow.size();k++)
                            {
                                int childR = node.first + delrow[k];
                                int childC = node.second + delcol[k];
                                
                                //check 3 conditions
                                if((childR >=0 && childR<m && childC >=0 && childC <n) && !visited[childR][childC] && grid[childR][childC] == 1)
                                {
                                    q.push({childR,childC});
                                    visited[childR][childC] = 1;
                                    temp.push_back({childR-baseX,childC-baseY});
                                }
                            }
                            countNodes--;
                        }
                    }
                    st.insert(temp);
                }
            }
        }
        return st.size();
        
    }



//Store different island shaped is set (SUBTRACT BASE FROM EACH ISLAND)
  //Using DFS
  void dfs(vector<vector<int>>& grid, int i,int j, int baseX, int baseY, int m, int n, vector<vector<int>>& visited, vector<int> delrow, vector<int> delcol, vector<pair<int,int>>& temp )
  {
      //root
      visited[i][j] = 1;
      temp.push_back({i-baseX,j-baseY});
      
      //call children
      for(int k=0;k<delrow.size();k++)
      {
          int childR = i + delrow[k];
          int childC = j + delcol[k];
          
          //check 3 conditions
          if((childR >=0 && childR <m && childC >=0 && childC<n) && !visited[childR][childC] && grid[childR][childC]==1)
          {
              dfs(grid,childR,childC,baseX,baseY,m,n,visited,delrow,delcol,temp);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>> visited(m,vector<int> (n,0));
       vector<int> delrow = {-1,0,1,0};
       vector<int> delcol = {0,-1,0,1};
       set<vector<pair<int,int>>> st;
       //need to visited all components
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j] == 1 && !visited[i][j])
               {
                   int baseX = i;
                   int baseY = j;
                   vector<pair<int,int>> temp;
                   dfs(grid,i,j,baseX,baseY,m,n,visited,delrow,delcol,temp);
                   st.insert(temp);
               }
           }
       }
       return st.size();
    }