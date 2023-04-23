    //componenets of O which have a node at a boundary will never be surrounded by X on all 4 sides
    //so we mark them visited without flippling
    //then we simply traverse the matrix and flip the remaining 0's
    //here we are asked to modify the original board
    // Using BFS
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        //collecting 0s on boundary
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||i==m-1||j==0||j==n-1) && board[i][j] =='O')
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                pair<int,int> node = q.front();
                q.pop();
                
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    
                    //satisfy 3 conditions 
                    if((childR>=0 && childR<m && childC >=0 && childC<n) && !visited[childR][childC] && board[childR][childC] =='O')
                    {
                        visited[childR][childC] = 1;
                        q.push({childR,childC});
                    }
                }
                countNodes--;
            }
        }
        
        //flip remaining Os
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }




    //USing DFS
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<int>>& visited,vector<int> delrow,vector<int> delcol)
    {
        //root
        visited[i][j] = 1;
        
        //call children
        for(int k=0;k<delrow.size();k++)
        {
            int childR = i + delrow[k];
            int childC = j + delcol[k];
            
            if((childR>=0 && childR<m && childC >=0 && childC<n) && !visited[childR][childC] && board[childR][childC] =='O')
            {
                visited[childR][childC] = 1;
                dfs(board,childR,childC,m,n,visited,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        
        //visit the boundary O components without flipping them
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||i==m-1||j==0||j==n-1) && board[i][j] == 'O')
                    dfs(board,i,j,m,n,visited,delrow,delcol);
            }
        }
        //flip the unvisisted 'O'
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }