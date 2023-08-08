// Method 1 : Nqueens 1 --> return ans.size();

// Method 2:
// Not using extra space for ans as in N queens 1
// just keeping a count becuase if we reach col ==n  means we found a new soln cnt ++
bool isValid(vector<string> &board, int row, int col, int n)
{
    // to check if valid, no queen should be placed in that row or column or diagonal(upper left and lower left)
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q') // checking row
            return false;
        if (board[i][col] == 'Q') // checking col //will never give false bcz we are moving col wise
            return false;
    }
    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = row, j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i++;
        j--;
    }
    return true;
}
void f(int &cnt, vector<string> &board, int col, int n)
{
    if (col == n) // reached Last row -- all ok till here
    {
        cnt++;
        return;
    }
    // Trying every row for colth column starting from 0
    for (int row = 0; row < n; row++)
    {
        if (isValid(board, row, col, n)) // first check if its safe to place Q at board[row][col]
        {
            board[row][col] = 'Q';
            f(cnt, board, col + 1, n); // put for next column
            board[row][col] = '.';     // remove while going back
        }
    }
}
int totalNQueens(int n)
{
    int cnt = 0;
    vector<string> board;
    string s = string(n, '.');
    for (int i = 0; i < n; i++)
        board.push_back(s);
    f(cnt, board, 0, n);
    return cnt;
}