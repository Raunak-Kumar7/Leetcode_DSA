// Same for N-Queens2 lc52

// https://leetcode.com/problems/n-queens/
// https://leetcode.com/problems/n-queens-ii/

// Try Out All Possibilities

// Conditions to be Satisified:
//  1. Each column has 1 queen
//  2. Each row has 1 queen
//  3. No 2 queens should attack each other

// moving column wise and plaing queen in every possible row of each column

// Backtracking Rule: Remove while going back
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
void f(vector<vector<string>> &ans, vector<string> &board, int col, int n)
{
    if (col == n) // reached Last row -- all ok till here
    {
        ans.push_back(board);
        return;
    }
    // Trying every row for colth column starting from 0
    for (int row = 0; row < n; row++)
    {
        if (isValid(board, row, col, n)) // first check if its safe to place Q at board[row][col]
        {
            board[row][col] = 'Q';
            f(ans, board, col + 1, n); // put for next column
            board[row][col] = '.';     // remove while going back
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board;
    string s = string(n, '.');
    for (int i = 0; i < n; i++)
        board.push_back(s);
    f(ans, board, 0, n);
    return ans;
}