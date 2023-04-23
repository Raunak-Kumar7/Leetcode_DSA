    //Matrix element can be seen as nodes {i,j}
    //There can be difference rectangular components --> we need to return top left and bottom right of each component
    //using BFS 

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {0,1}; //moving only down and right as all are rectangular
        vector<int> delcol = {1,0}; 
        vector<vector<int>> ans;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && land[i][j]==1)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    vector<int> temp(4);
                    temp[0] = i;//r1
                    temp[1] = j;//c1
                    temp[2] = i; //initialising also with i,j becuase maybe a single unit farmland so doesnt go inside BFS
                    temp[3] = j;
                    while(!q.empty())
                    {
                        int countNodes = q.size();
                        while(countNodes>0)
                        {
                            pair<int,int> node = q.front();
                            q.pop();

                            for(int k=0;k<delrow.size();k++)
                            {
                                int childR = node.first + delrow[k];
                                int childC = node.second + delcol[k];

                                //check 3 conditions
                                if((childR>=0 && childR<m && childC >=0 && childC <n) && !visited[childR][childC] && land[childR][childC] == 1)
                                {
                                    q.push({childR,childC});
                                    visited[childR][childC] = 1;
                                    temp[2] = max(temp[2],childR);//keep updating bcz right most will have max row and max col values
                                    temp[3] = max(temp[3],childC);
                                }
                            }
                            countNodes--;
                        }
                    }
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }


//using DFS
    void dfs(vector<vector<int>>& land, int r, int c, int m, int n ,vector<vector<int>>& visited, vector<int>& temp,vector<int> delrow,vector<int> delcol)
    {
        //root
        visited[r][c] = 1;
        
        //children
        for(int i=0;i<delrow.size();i++)
        {
            int childR = r + delrow[i];
            int childC = c + delcol[i];

            //check 3 conditions
            if((childR>=0 && childR<m && childC >=0 && childC <n) && !visited[childR][childC] && land[childR][childC]==1)
            {
                visited[childR][childC] = 1;
                temp[2] = max(temp[2],childR);
                temp[3] = max(temp[3],childC);
                dfs(land,childR,childC,m,n,visited,temp,delrow,delcol);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {0,1}; //only rectangular lands so move down or right
        vector<int> delcol = {1,0};
        vector<vector<int>> ans;
        //we need to check for all the components
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(!visited[i][j] && land[i][j]==1)
                {
                    vector<int> temp(4,0);
                    temp[0] = i;
                    temp[1] = j;
                    temp[2] = i;//initialising second index with i, j becuase it may be a 1 unit cell
                    temp[3] = j;
                    dfs(land,i,j,m,n,visited,temp,delrow,delcol);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }