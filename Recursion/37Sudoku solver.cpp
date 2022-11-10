
//https://leetcode.com/problems/sudoku-solver/

bool isValid(vector<vector<char>>& board, char k, int row, int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==k)//column condition
                return false;
            if(board[row][i]==k)//row condition
                return false;
        }
        int x,y;
        if(row<3) x=0;//block condition
        else if(row<6) x=3;
        else x=6;
        
        if(col<3) y=0;
        else if(col<6) y=3;
        else y=6;
            
        for(int i=x;i<x+3;i++)
            for(int j=y;j<y+3;j++)
                if(board[i][j]==k)
                    return false;
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.') //now we try to fill
                {
                    for(char k='1';k<='9';k++)// we check for all possible values which can be filled
                    {
                        
                        if(isValid(board,k,i,j)==true)//if k without any collision is found
                        {
                            board[i][j]=k;
                            if(solve(board)==true)//moving forward by filling k 
                                return true;
                            else                    //if returned false means we k was not fit so remove it
                                board[i][j]='.';
                        }
                    }
                    return false;//if on an empty location we are not able to fit any number 1-9,means some previous was wrong
                }
            }
        }
        return true; // if we traversed everything and at last no conflict
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }