//Same for N-Queens2 lc52

//https://leetcode.com/problems/n-queens/
//https://leetcode.com/problems/n-queens-ii/



bool isValid(int row,int col, vector<string>& board,int n)
    {
        //we dont need to check columns bcz we are filling column by column
        //we only need to check 3 directions left top left and bottom left, bcz right side is not filled yet
        int duprow = row;
        int dupcol = col;
        //top left
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        //left
        row = duprow;
        col = dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        //bottom left
        row = duprow;
        col = dupcol;
        while(col>=0 && row<n)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>& ans, vector<string>& board,int n )
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++) //try
        {
            if(isValid(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.'; //while backtracking remove the previous entred
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //making 1D board
        vector<string> board(n); //nrows
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
    }