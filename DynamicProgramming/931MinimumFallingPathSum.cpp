// Similar to Triangle problem
// Only difference here is that here neither the starting point nor the ending point is fixed

// Approach 1: Recursive Solution [In recursion Base condition handles out of bound conditions]
int f(int i, int j, int m, vector<vector<int>> &matrix)
{
    if (i < 0 || j < 0 || j >= m) // This condition should be put before in case index goes out of bound
    {                             // Out of Bound Base condition
        return 1e8;               // Min so to include return a large number
    }
    if (i == 0) // Means reached first row destination Base case
    {
        return matrix[i][j]; // Destination Base Condition
    }
    int up = matrix[i][j] + f(i - 1, j, m, matrix);
    int upleft = matrix[i][j] + f(i - 1, j - 1, m, matrix);
    int upright = matrix[i][j] + f(i - 1, j + 1, m, matrix);
    return min(min(up, upleft), upright);
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    // We apply triangle approach but on all columns and take the minimum
    // As Both are variable we can start either from 0 or from m
    int mini = INT_MAX;
    for (int j = m - 1; j >= 0; j--)
    {
        mini = min(mini, f(m - 1, j, m, matrix));
    }
    return mini;
}

// Approach 1:Memoized Solution
int f(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || j >= m) // This condition should be put before in case index goes out of bound
    {                             // Out of Bound Base condition
        return 1e8;               // Min so to include return a large number
    }
    if (i == 0) // Means reached first row destination Base case
    {
        return matrix[i][j]; // Destination Base Condition
    }
    if (dp[i][j] != -1)
        return dp[i][j]; // S3
    int up = matrix[i][j] + f(i - 1, j, m, matrix, dp);
    int upleft = matrix[i][j] + f(i - 1, j - 1, m, matrix, dp);
    int upright = matrix[i][j] + f(i - 1, j + 1, m, matrix, dp);
    return dp[i][j] = min(min(up, upleft), upright); // S2
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    // We apply triangle approach but on all columns and take the minimum
    // As Both are variable we can start either from 0 or from m
    int mini = INT_MAX;
    vector<vector<int>> dp(m, vector<int>(m, -1)); // S1
    for (int j = m - 1; j >= 0; j--)
    {
        mini = min(mini, f(m - 1, j, m, matrix, dp));
    }
    return mini;
}

// Approach 3:Tabulation Solution
int f(int size, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0)
                dp[i][j] = matrix[i][j];
            else
            {
                int up = 1e8;
                int upleft = 1e8;
                int upright = 1e8;
                if (i > 0)
                    up = matrix[i][j] + dp[i - 1][j];
                if (i > 0 && j > 0)
                    upleft = matrix[i][j] + dp[i - 1][j - 1];
                if (i > 0 && j < size - 1)
                    upright = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(min(up, upleft), upright);
            }
        }
    }
    // Minimum value can lie anywhere in last row
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, dp[size - 1][i]);
    }
    return mini;
    // return dp[size-1][size-1];
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    // We apply triangle approach but on all columns and take the minimum
    // As Both are variable we can start either from 0 or from m
    vector<vector<int>> dp(m, vector<int>(m, -1)); // S1
    return f(m, matrix, dp);
}

// Approach 4:Tabulation Solution -->Space Optimisation
int f(int m, vector<vector<int>> &matrix)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(m, -1);
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
                curr[j] = matrix[i][j];
            else
            {
                // We only require one previous row of dp array
                int up = 1e8;
                int upleft = 1e8;
                int upright = 1e8;
                if (i > 0)
                    up = matrix[i][j] + prev[j];
                if (i > 0 && j > 0)
                    upleft = matrix[i][j] + prev[j - 1];
                if (i > 0 && j < m - 1)
                    upright = matrix[i][j] + prev[j + 1];
                curr[j] = min(min(up, upleft), upright);
            }
        }
        prev = curr;
    }
    // Minimum value can lie anywhere in last row
    // prev == curr == last row
    int mini = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        mini = min(mini, prev[i]);
    }
    return mini;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    return f(m, matrix);
}