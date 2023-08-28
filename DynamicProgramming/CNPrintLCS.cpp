// Direct Tabulation for this ques
string findLCS(int m, int n, string &s1, string &s2)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	// matrix filled
	string ans = "";
	int i = m;
	int j = n;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			ans = s1[i - 1] + ans;
			i--;
			j--;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	return ans;
}