    //DIstance of nearest 0
    //We have to return the distance of nearest 0 so we have to move level wise
    //Using BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        vector<vector<int>> dist = mat;
        
        //we need to start from all 1s and mark --> we need to keep dist
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && dist[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                pair<pair<int,int>,int> p = q.front();
                q.pop();
                
                pair<int,int> node = p.first;
                int di = p.second;
                
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    
                    //3 conditions
                    if((childR>=0 && childR<m && childC>=0 && childC <n) && !visited[childR][childC] && dist[childR][childC]!=0)
                    {
                        dist[childR][childC] = di + 1;
                        visited[childR][childC] = 1;
                        q.push({{childR,childC},di+1});
                    }
                }
                countNodes--;   
            }
        }
        return dist;
    }