// similar to unbounded knapsack (collect rod sizes to form n)
// 1 based indexing
int f(int i, int price[], int n)
{
    if (n == 0 || i == -1)
        return 0;

    int pick = INT_MIN;
    if (i + 1 <= n)
        pick = price[i] + f(i, price, n - (i + 1));
    int notPick = f(i - 1, price, n);

    return max(pick, notPick);
}
int cutRod(int price[], int n)
{
    return f(n - 1, price, n);
}

// similar to unbounded knapsack (collect rod sizes to form n)
// 1 based indexing
// memoization
int f(int i, int price[], int n, vector<vector<int>> &dp)
{
    if (n == 0 || i == -1)
        return 0;
    if (dp[i][n] != -1)
        return dp[i][n];
    int pick = INT_MIN;
    if (i + 1 <= n)
        pick = price[i] + f(i, price, n - (i + 1), dp);
    int notPick = f(i - 1, price, n, dp);

    return dp[i][n] = max(pick, notPick);
}
int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, price, n, dp);
}

// tabulation
int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0)); //{price, size}
    for (int i = 0; i < n; i++)
    {
        for (int sz = 0; sz <= n; sz++)
        {
            if (sz == 0)
                dp[i][sz] = 0;
            else if (i == 0)
            {
                dp[i][sz] = sz * price[i];
            }
            else
            {
                int pick = INT_MIN;
                if (sz >= i + 1)
                    pick = price[i] + dp[i][sz - (i + 1)]; // i because unbounded
                int notPick = dp[i - 1][sz];

                dp[i][sz] = max(pick, notPick);
            }
        }
    }
    return dp[n - 1][n];
}