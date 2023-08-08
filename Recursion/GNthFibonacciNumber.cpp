// Sum of last 2
#define MOD 1000000007
class Solution
{
public:
    int f(int n)
    {
        if (n == 0 || n == 1)
            return n;

        return (f(n - 2) % MOD + f(n - 1) % MOD) % MOD;
    }
    int nthFibonacci(int n)
    {
        return f(n);
    }

    // --------------

    // Memoization
#define MOD 1000000007
    class Solution
    {
    public:
        int f(int n, vector<int> &dp)
        {
            if (n == 0 || n == 1)
                return n;

            if (dp[n] != -1)
                return dp[n];
            return dp[n] = (f(n - 2, dp) % MOD + f(n - 1, dp) % MOD) % MOD;
        }
        int nthFibonacci(int n)
        {
            vector<int> dp(n + 1, -1);
            return f(n, dp);
        }