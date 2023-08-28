// unbounded knapsack --> can pick multiple times
// recursion
int f(int i, int W, int val[], int wt[])
{
    if (i == 0)
    {
        if (W >= wt[i])
            return (W / wt[i]) * val[i];
        return 0;
    }
    int take = 0;
    if (wt[i] <= W)
        take = val[i] + f(i, W - wt[i], val, wt);
    int notTake = f(i - 1, W, val, wt);

    return max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{
    return f(N - 1, W, val, wt);
}

// memoization

int f(int i, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (W >= wt[i])
            return (W / wt[i]) * val[i];
        return 0;
    }
    if (dp[i][W] != -1)
        return dp[i][W];
    int take = 0;
    if (wt[i] <= W)
        take = val[i] + f(i, W - wt[i], val, wt, dp);
    int notTake = f(i - 1, W, val, wt, dp);

    return dp[i][W] = max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return f(N - 1, W, val, wt, dp);
}

// Tabulation
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, 0));

    for (int i = 0; i < N; i++) // for item
    {
        for (int j = 0; j <= W; j++) // for weight
        {
            if (i == 0 && j != 0) // can't divide by 0
            {
                dp[i][j] = (j / wt[0]) * val[0];
            }
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                int pick = 0;
                if (wt[i] <= j)
                    pick = val[i] + dp[i][j - wt[i]];
                int notPick = dp[i - 1][j]; // not picking -->  same profit

                dp[i][j] = max(pick, notPick);
            }
        }
    }
    return dp[N - 1][W];
}