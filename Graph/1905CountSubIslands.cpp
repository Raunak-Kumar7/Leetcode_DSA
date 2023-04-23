//need to count number of components in grid 2 -- the entire component in grid 2 should also have 1s in grid1 // --> simple count number of connected components just check if its also 1 in grid 1
    
    //using BFS
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        int count = 0;
        //all components
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid2[i][j]==1 && grid1[i][j]==1)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    count++;
                    bool flag = false;
                    while(!q.empty())
                    {
                        int countNodes = q.size();
                        while(countNodes > 0)
                        {
                            pair<int,int> node = q.front();
                            q.pop();
                            
                            for(int k = 0;k<delrow.size();k++)
                            {
                                int childR = node.first + delrow[k];
                                int childC = node.second + delcol[k];
                                
                                if((childR>=0 && childR <m && childC>=0 && childC<n) && !visited[childR][childC] && grid2[childR][childC]==1)
                                {
                                    if(grid1[childR][childC]!=1) flag = true; //if not there in grid 1 still visit the component but after decrease the count
                                    
                                    q.push({childR,childC});
                                    visited[childR][childC] = 1; 
                                }
                            }
                            countNodes--;
                        }
                    }
                    if(flag) count--;
                }
            }
        }
        return count;
        
        
    }