    //can write BFS as a function to shorten the code
    // a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
    
    //So first we remove components/islands that have an element at boundary becuase those islands cant be closed TOTALLY. Remaining components are closed islands
    
    //Using BFS
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r,vector<int> (c,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if((i==0 ||i==r-1 ||j==0 ||j==c-1) && !visited[i][j] && grid[i][j]==0)
                {
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
                                if((childR >= 0 && childR < r && childC >= 0 && childC < c) && !visited[childR][childC] && grid[childR][childC]==0)
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

         //now counting the remaining number of components
        int cnt = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!visited[i][j] && grid[i][j]==0)
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
                                if((childR >= 0 && childR < r && childC >= 0 && childC < c) && !visited[childR][childC] && grid[childR][childC]==0)
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