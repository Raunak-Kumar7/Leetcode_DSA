//Doing MultiSource BFS from 1 island
    int shortestBridge(vector<vector<int>>& grid) {
        //as there are only 2 islands color each island with a different color
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        int color = 1;
        queue<pair<pair<int,int>,int>> q2; //{island1 coordinates, 0}
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = color;
                    if(color==1) q2.push({{i,j},0});
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
                                if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] && grid[childR][childC]==1)
                                {
                                    q.push({childR,childC});
                                    visited[childR][childC]=color;
                                    if(color==1) q2.push({{childR,childC},0});
                                }
                            }
                            countNodes--;
                        }
                    }
                    color++;
                }
            }
        }
 
        //now visited has one island with color 1 and 1 island with color 2
        while(!q2.empty()) //multisource BFS
        {
            int countNodes = q2.size();
            while(countNodes>0)
            {
                pair<int,int> node = q2.front().first;
                int d = q2.front().second;
                q2.pop();
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    if((childR>=0 && childR<m && childC>=0 && childC<n)  && visited[childR][childC]==2)
                        return d;
                    if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] )
                    {
                        q2.push({{childR,childC},d+1});
                        visited[childR][childC] = 1;
                    }
                }
                countNodes--;
            }
        }
        return -1;
    }