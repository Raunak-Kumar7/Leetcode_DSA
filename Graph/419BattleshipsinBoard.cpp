    //We basically need to find number of components
    //Here BfS wont work because we dont need to find in all the directions(it will work because we want just no of components)
    //We have to move in a single direction
    
    //IMP --> At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
    //So simply finding number of components
    
    //Using DFS
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n, vector<vector<int>>& visited, vector<int> delrow, vector<int> delcol)
    {
         //root
        visited[r][c] = 1;
        
        //calling children
        for(int i=0;i<delrow.size();i++)
        {
            int childR = r + delrow[i];
            int childC = c + delcol[i];
            
            if((childR>=0 && childR<m && childC>=0 && childC<n) && !visited[childR][childC] && board[childR][childC] == 'X')
            {
                dfs(board,childR,childC,m,n,visited,delrow,delcol);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        //We either need to keep moving down or keep moving right NOT both
        vector<int> delrow = {0,1};
        vector<int> delcol = {1,0};
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && board[i][j] == 'X')
                {
                    count++;
                    dfs(board,i,j,m,n,visited,delrow,delcol);
                }
            }
        }
        return count;
    }


//////----- can also be done using BFS because we are only finding number of components---
//as there is space between 2 ships