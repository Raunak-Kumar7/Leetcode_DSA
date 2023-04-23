//Using BFS
    // (if a visited node is found which is not A PARENT --> CYCLE FOUND)
    //keep a parent variabele also
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        for(char c='a';c<='z';c++)   //O(26*n^2)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[i][j] && grid[i][j]==c)
                    {
                        queue<pair<pair<int,int>,pair<int,int>>> q;
                        q.push({{i,j},{-1,-1}});  //node, parent
                        visited[i][j] = 1;
                        
                        while(!q.empty())
                        {
                            int countNodes = q.size();
                            while(countNodes > 0)
                            {
                                pair<int,int> node = q.front().first;
                                pair<int,int> parent = q.front().second;
                                q.pop();
                                
                                for(int k=0;k<delrow.size();k++)
                                {
                                    int childR = node.first + delrow[k];
                                    int childC = node.second + delcol[k];
                                    
                                    if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] && grid[childR][childC]==c)
                                    {
                                        q.push({{childR,childC},{node.first,node.second}});
                                        visited[childR][childC] = 1;
                                    }
                                    else if((childR>=0 && childR<m && childC>=0 && childC<n) && grid[childR][childC]==c && (childR!=parent.first || childC!=parent.second) && visited[childR][childC])
                                    {//visited but not a parent
                                        return true;
                                    }
                                }
                                countNodes--;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }