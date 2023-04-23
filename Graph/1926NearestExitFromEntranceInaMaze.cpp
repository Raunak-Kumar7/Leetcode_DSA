//We need to start from all boundary cells and mark visited(with distance) all the nearby empty cells 
    //Using BFS (multiSource ON boundary)
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        
        queue<pair<pair<int,int>, int>> q;
        //push all sources on boundary
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1) //Boundary condition
                {
                    if(!visited[i][j] && maze[i][j]=='.')
                    {
                        if(entrance[0]==i && entrance[1]==j) continue; // again visit it from somewhere elseand dont push in queue
                        q.push({{i,j},0}); // we can maintian the dist matrix too but it can be done also without it, like when we encounter entrance we just return 
                        visited[i][j] = 1;
                        //entrance cell doesnt count as exit cell
                        
                    }
                }
            }
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                pair<int,int> node = q.front().first;
                int d = q.front().second;
                q.pop();
                
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    
                    if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] && maze[childR][childC]=='.')
                    {
                        q.push({{childR,childC},d+1});
                        visited[childR][childC] = 1;
                        if(entrance[0]==childR && entrance[1]==childC)
                            return d+1;
                    }
                }
                countNodes--;
            }
        }
        return -1; //not reachable i.e. land (wall) locked
    }