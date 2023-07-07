//BFS
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int x = click[0];
        int y = click[1];
        vector<int> delrow = {-1,-1,-1,0,0,0,1,1,1};
        vector<int> delcol = {-1,0,1,-1,0,1,-1,0,1};
        if(board[x][y]=='M')
        {
            board[x][y] = 'X';
            return board;
        }
        //no need for all components
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        
        q.push({x,y});
        int adjacentMines = 0;
        for(int j=0;j<delrow.size();j++)
        {
            int childR2 = x+delrow[j];
            int childC2 = y+delcol[j];
            if((childR2>=0 && childR2<m)&&(childC2>=0 && childC2<n) && board[childR2][childC2]=='M')    
            {
                adjacentMines++;
            }
        }
        if(adjacentMines!=0)
        {
            board[x][y] = '0' + adjacentMines;
            return board;
        }
        else
        {
            board[x][y] = 'B';
        }
        visited[x][y] = 1;
        
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                pair<int,int> node = q.front();
                int xx = node.first;
                int yy = node.second;
                q.pop();
                for(int i = 0;i<delrow.size();i++)
                {
                    int childR = xx+delrow[i];
                    int childC = yy+delcol[i];
                    if((childR>=0 && childR<m)&&(childC>=0 && childC<n) && !visited[childR][childC])
                    {
                        //------
                        int adjacentMines = 0;
                        for(int j=0;j<delrow.size();j++)
                        {
                            int childR2 = childR+delrow[j];
                            int childC2 = childC+delcol[j];
                            if((childR2>=0 && childR2<m)&&(childC2>=0 && childC2<n) && board[childR2][childC2]=='M')    
                            {
                                adjacentMines++;
                            }
                        }
                        //-------
                        if(board[childR][childC]=='E' && adjacentMines!=0)
                        {
                            board[childR][childC] = '0' + adjacentMines ;
                            ///dont call bfs
                            visited[childR][childC];
                        }
                        else if(board[childR][childC]=='E') //no adjacent mines
                        {
                            board[childR][childC] = 'B';
                            q.push({childR,childC});
                            visited[childR][childC];
                        }
                    }
                }
                countNodes--;
            }
        }
        return board;
    }