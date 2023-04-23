//LC 286

//As nearest is required(i.e. min distance)
//we need to travel level wise --> BFS

//Question is exactly same as 0/1 matrix(distance of nearest 1 from each cell)
// ++ here we also have walls
//we keep {node,distance} in queue

//We just need to avoid the walls -1 no need to put any check
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    
    //multisource --> for all gates
    queue<pair<pair<int,int>, int>> q;
    vector<vector<int>> visited(n,vector<int> (m,0));
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,-1,0,1};
    vector<vector<int>> grid = a; //not changing the original array
    for(int i=0;i<n;i++)//push all gates
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
            {
                q.push({{i,j},0});
                visited[i][j] = 1;
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

            int dist = p.second;
            pair<int,int> node = p.first;

            //push all children
            for(int i=0;i<delrow.size();i++)
            {
                int childR = node.first + delrow[i];
                int childC = node.second + delcol[i];

                if((childR>=0 && childR<n && childC>=0 && childC <m) && !visited[childR][childC] && grid[childR][childC]==INT_MAX)
                {
                  q.push({{childR, childC}, dist + 1});
                  grid[childR][childC] = dist + 1;
                  visited[childR][childC] = 1;
                }
            }
            countNodes--;
        }
    }
    return grid;
}