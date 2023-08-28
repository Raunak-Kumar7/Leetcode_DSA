// Number of ways in a unbounded knapsack(in this 0 wont be there in coins)
// it is not MINIMUM number of coins
// recursion
int f(int i, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (i == 0)
    {
        if (amount % coins[i] == 0)
            return 1;
        else
            return 0;
    }

    int pick = 0;
    if (amount >= coins[i])
        pick = f(i, amount - coins[i], coins);
    int notPick = f(i - 1, amount, coins);

    return pick + notPick;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    return f(n - 1, amount, coins);
}

// memoization
int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;
    if (i == 0)
    {
        if (amount % coins[i] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][amount] != -1)
        return dp[i][amount];
    int pick = 0;
    if (amount >= coins[i])
        pick = f(i, amount - coins[i], coins, dp);
    int notPick = f(i - 1, amount, coins, dp);

    return dp[i][amount] = pick + notPick;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return f(n - 1, amount, coins, dp);
}

// Tabulation
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a <= amount; a++)
        {
            if (i == 0)
            {
                if (a % coins[i] == 0)
                    dp[i][a] = 1;
                else
                    dp[i][a] = 0;
            }
            else if (a == 0)
            {
                dp[i][a] = 1; // to make 0 sum there is 1 way
            }
            else
            {
                int pick = 0;
                if (a >= coins[i])
                    pick = dp[i][a - coins[i]]; // number of ways remain same
                int notPick = dp[i - 1][a];
                dp[i][a] = pick + notPick;
            }
        }
    }
    return dp[n - 1][amount];
}