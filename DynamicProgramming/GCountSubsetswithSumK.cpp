// Instead of T/F store count in dp
// Recursion
// Handle 0 --> at the end muliply with 2^(number of 0s)
#define MOD 1000000007
int f(int i, int arr[], int sum)
{                 // not considering 0s, 0s handled in main
    if (sum == 0) // this condition should come first/ else WA ,
        return 1;
    else if (i == 0)
    {
        return arr[i] == sum;
    }
    int pick = 0;
    if (arr[i] <= sum && arr[i] != 0) // in bounded knapsack condition on 0s should be here i.e. we dont pick if its 0
        pick = f(i - 1, arr, sum - arr[i]);
    int notPick = f(i - 1, arr, sum);

    return (pick + notPick) % MOD;
}
int perfectSum(int arr[], int n, int sum)
{
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
    }
    int x = pow(2, zero);
    x = x % MOD;
    return (f(n - 1, arr, sum) * x) % MOD;
}

// memoization
// Handle 0 --> at the end muliply with 2^(number of 0s)
#define MOD 1000000007
int f(int i, int arr[], int sum, vector<vector<int>> &dp)
{                 // not considering 0s, 0s handled in main
    if (sum == 0) // this condition should come first/ else WA ,
        return 1;
    else if (i == 0)
    {
        return arr[i] == sum;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int pick = 0;
    if (arr[i] <= sum && arr[i] != 0) // in bounded knapsack condition on 0s should be here i.e. we dont pick if its 0
        pick = f(i - 1, arr, sum - arr[i], dp);
    int notPick = f(i - 1, arr, sum, dp);

    return dp[i][sum] = (pick + notPick) % MOD;
}
int perfectSum(int arr[], int n, int sum)
{
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
    }
    int x = pow(2, zero);
    x = x % MOD;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return (f(n - 1, arr, sum, dp) * x) % MOD;
}

// tabulation
// Handle 0 --> at the end muliply with 2^(number of 0s)
#define MOD 1000000007
int perfectSum(int arr[], int n, int sum)
{
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
    }
    int x = pow(2, zero);
    x = x % MOD;
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            if (s == 0) // should be written first
            {
                dp[i][s] = 1;
            }
            else if (i == 0)
            {
                if (s == arr[i])
                    dp[i][s] = 1;
                else
                    dp[i][s] = 0;
            }
            else
            {
                int pick = 0;
                if (s >= arr[i] && arr[i] != 0) // 0s handled separatly Always not pick
                    pick = dp[i - 1][s - arr[i]] % MOD;
                int notPick = dp[i - 1][s] % MOD;
                dp[i][s] = (pick + notPick) % MOD;
            }
        }
    }
    return (dp[n - 1][sum] * x) % MOD;
}