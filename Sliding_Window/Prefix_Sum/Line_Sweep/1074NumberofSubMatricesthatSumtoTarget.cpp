// 2D Line Sweep
int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0)); //+1 to make easy i-1,j-1 calculations

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    // now we have sums of all sub matrices in 1-m, 1-n of prefix
    // we will check for all sub matrices if their sum = target

    int count = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            // generating all end points of sub matrices
            for (int i2 = i; i2 <= m; i2++)
            {
                for (int j2 = j; j2 <= n; j2++)
                {
                    int ans = prefix[i2][j2] - prefix[i2][j - 1] - prefix[i - 1][j2] + prefix[i - 1][j - 1];
                    if (ans == target)
                        count++;
                }
            }
        }
    }
    return count;
}