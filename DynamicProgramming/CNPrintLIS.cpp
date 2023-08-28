// 1d dp
vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n)
{
	vector<int> dp(n, 1);
	vector<int> parent(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	dp[0] = 1;
	int maxi = 1;
	int maxidx = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				if (dp[i] <= 1 + dp[j])
				{
					dp[i] = 1 + dp[j];
					parent[i] = j;
					if (dp[i] > maxi)
					{
						maxi = dp[i];
						maxidx = i;
					}
				}
			}
		}
	}
	// dp array formed along with parent;
	vector<int> ans;
	int i = maxidx;
	while (i != parent[i])
	{
		ans.push_back(nums[i]);
		i = parent[i];
	}
	ans.push_back(nums[i]);
	reverse(ans.begin(), ans.end());

	return ans;
}
