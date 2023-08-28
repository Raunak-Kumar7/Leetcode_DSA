// Recursion
int f(int i, vector<int> &coins, int amount)
{
    if (i == 0)
    {
        if (amount % coins[i] == 0)
            return amount / coins[i];
        return 1e9; // min number of coins is asked
    }

    int pick = 1e9; // else overflow
    if (coins[i] <= amount)
        pick = 1 + f(i, coins, amount - coins[i]);
    int notPick = f(i - 1, coins, amount);

    return min(pick, notPick);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    int ans = f(n - 1, coins, amount);
    return ans == 1e9 ? -1 : ans;
}

// Memoization
int f(int i, vector<int> &coins, int amount, vector<vector<int>> dp)
{
    if (i == 0)
    {
        if (amount % coins[i] == 0)
            return amount / coins[i];
        return 1e9; // min number of coins is asked
    }
    if (dp[i][amount] != -1)
        return dp[i][amount];
    int pick = 1e9; // else overflow
    if (coins[i] <= amount)
        pick = 1 + f(i, coins, amount - coins[i], dp);
    int notPick = f(i - 1, coins, amount, dp);

    return dp[i][amount] = min(pick, notPick);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, coins, amount, dp);
    return ans == 1e9 ? -1 : ans;
}

// Tabulation
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c <= amount; c++)
        {
            if (i == 0)
            {
                if (c % coins[i] == 0)
                    dp[i][c] = c / coins[i];
                else
                    dp[i][c] = 1e9;
            }
            else if (c == 0)
            {
                dp[i][c] = 0;
            }
            else
            {
                int pick = 1e9;
                if (coins[i] <= c)
                    pick = 1 + dp[i][c - coins[i]];
                int notPick = dp[i - 1][c];
                dp[i][c] = min(pick, notPick);
            }
        }
    }
    return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
}