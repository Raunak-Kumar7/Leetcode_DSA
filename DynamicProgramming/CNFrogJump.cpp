int f(int idx, vector<int> &heights)
{
    if (idx == 0)
        return 0;

    int oneStep = f(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);
    int twoStep = INT_MAX;
    if (idx > 1)
        twoStep = f(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);

    return min(oneStep, twoStep);
}
int frogJump(int n, vector<int> &heights)
{
    return f(n - 1, heights);
}

// memoized
int f(int idx, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];
    int oneStep = f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
    int twoStep = INT_MAX;
    if (idx > 1)
        twoStep = f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

    return dp[idx] = min(oneStep, twoStep);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return f(n - 1, heights, dp);
}

// tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++)
    {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n - 1];
}

// tabulation - space optimisation
int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int curr = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++)
    {
        int oneStep = curr + abs(heights[i] - heights[i - 1]);
        int twoStep = prev + abs(heights[i] - heights[i - 2]);
        prev = curr;
        curr = min(oneStep, twoStep);
    }
    return curr;
}