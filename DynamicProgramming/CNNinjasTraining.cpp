// Recursion

int f(int i, int last, vector<vector<int>> &points)
{
    if (i < 0)
        return 0;

    int maxi = INT_MIN;
    for (int j = 0; j < 3; j++)
    {
        if (j != last)
        {
            maxi = max(maxi, points[i][j] + f(i - 1, j, points));
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n - 1, 3, points); //(day,last)
}

// memoisation
int f(int i, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;

    if (dp[i][last] != -1)
        return dp[i][last];
    int maxi = INT_MIN;
    for (int j = 0; j < 3; j++)
    {
        if (j != last)
        {
            maxi = max(maxi, points[i][j] + f(i - 1, j, points, dp));
        }
    }
    return dp[i][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1)); // bcz for last index we are using last = 3
    return f(n - 1, 3, points, dp);                //(day,last)
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    if (n == 1)
        return max(points[0][0], max(points[0][1], points[0][2]));
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int last = 0; last < 3; last++)
            {
                if (last != j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][last] + points[i][j]);
                }
            }
        }
    }
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

// Tabulation - space optimisation -- we only need one row before
int ninjaTraining(int n, vector<vector<int>> &points)
{
    if (n == 1)
        return max(points[0][0], max(points[0][1], points[0][2]));
    vector<int> dp(3, -1);
    vector<int> prev(3, -1);

    prev[0] = points[0][0];
    prev[1] = points[0][1];
    prev[2] = points[0][2];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int last = 0; last < 3; last++)
            {
                if (last != j)
                {
                    dp[j] = max(dp[j], prev[last] + points[i][j]);
                }
            }
        }
        prev = dp;
    }
    return max(prev[0], max(prev[1], prev[2]));
}