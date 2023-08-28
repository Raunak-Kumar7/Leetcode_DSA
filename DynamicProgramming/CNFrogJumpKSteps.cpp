// Recursion

int f(int i, int k, vector<int> &height)
{
    if (i == 0)
        return 0;

    int mini = INT_MAX;
    for (int idx = 1; idx <= k; idx++)
    {
        if (i - idx >= 0)
            mini = min(mini, f(i - idx, k, height) + abs(height[i] - height[i - idx]));
    }
    return mini;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    return f(n - 1, k, height);
}

// Memoization
int f(int i, int k, vector<int> &height, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;
    for (int idx = 1; idx <= k; idx++)
    {
        if (i - idx >= 0)
            mini = min(mini, f(i - idx, k, height, dp) + abs(height[i] - height[i - idx]));
    }
    return dp[i] = mini;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, -1);
    return f(n - 1, k, height, dp);
}

// Tabulation
//  (space optimisation not possible bcz we require k steps behind)
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = max(i - k, 0); j < i; j++)
        {
            mini = min(mini, dp[j] + abs(height[j] - height[i]));
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}