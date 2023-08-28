// Approach 1: Recusrsion
int f(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid)
{
    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) // Both robots can not move outside grid at the same moment
    {
        return -1e8;
    }
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    vector<int> r1 = {-1, 0, 1};
    vector<int> r2 = {-1, 0, 1};
    int maxi = INT_MIN;
    for (auto fi : r1) // trying out all permutations
    {
        for (auto s : r2)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += f(i + 1, j1 + fi, j2 + s, m, n, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    return f(0, 0, n - 1, m, n, grid); // f returns total number of cherries picked
    // As both move rows simultaneously so we can keep same i
    // Fixed starting point so we start from it
}

// Memoized Solution
int f(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) // Both robots can not move outside grid at the same moment
    {
        return -1e8;
    }
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    vector<int> r1 = {-1, 0, 1};
    vector<int> r2 = {-1, 0, 1};
    int maxi = INT_MIN;
    for (auto fi : r1) // trying out all permutations
    {
        for (auto s : r2)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += f(i + 1, j1 + fi, j2 + s, m, n, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    // changing parameters = 3 i,j1,j2
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return f(0, 0, n - 1, m, n, grid, dp);
}

// Tabulation
// 3d dp Because 3 changing parameters --> i,j1,j2
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    vector<int> del = {-1, 0, 1};
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                if (i == m - 1)
                {
                    if (j1 == j2)
                        dp[i][j1][j2] = grid[i][j1];
                    else
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                }
                else
                {
                    int val = 0;
                    for (auto it1 : del)
                    {
                        for (auto it2 : del)
                        {
                            if (j1 + it1 >= 0 && j1 + it1 < n && j2 + it2 >= 0 && j2 + it2 < n)
                                val = max(val, dp[i + 1][j1 + it1][j2 + it2]);
                        }
                    }
                    if (j1 == j2)
                    {
                        dp[i][j1][j2] = grid[i][j1] + val;
                    }
                    else
                    {
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + val;
                    }
                }
            }
        }
    }
    return dp[0][0][n - 1];
}