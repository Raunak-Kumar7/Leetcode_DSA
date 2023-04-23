//We have to travel level wise (Becuase it requires MINIMUM Time)
//BFS
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int time = 0;
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<vector<int>> arr = grid; //not update original array
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        //We have multiple starting points --> all rotten oranges
        queue<pair<int,int>> q;
        int cntFresh = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==2)
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
                else if(arr[i][j]==1)
                    cntFresh++;
            }
        }
        if(cntFresh == 0) return 0; //EDGE CASE if no fresh orange
        while(!q.empty())
        {
            int countNodes = q.size();
            time++;
            while(countNodes > 0)
            {
                pair<int,int> node = q.front();
                q.pop();

                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];

                    //satisfy 3 conditions
                    if((childR >= 0 && childR < m && childC >=0 && childC <n) && !visited[childR][childC] && arr[childR][childC]==1)
                    {
                        q.push({childR,childC});
                        arr[childR][childC] = 2;
                        visited[childR][childC];
                    }
                }
                countNodes--;
            }
        }
        for(auto i:arr)
        {
            for(auto j:i)
            {
                if(j==1)
                    return -1;
            }
        }
        return time-1; //at root its 0
    }
