//Directly using Tabulation Approach 
#include<bits/stdc++.h>
string f(int m, int n, string& s, string& t, vector<vector<int>>& dp)
{
	string ans = "";
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else
			{
				if(s[i-1]==t[j-1])
				{
					dp[i][j] = 1+dp[i-1][j-1];
					ans+=s[i-1];
				}
				else
				{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
					if(dp[i-1][j]>dp[i][j-1])
						ans+=s[i-1];
					else
						ans+=s[j-1];
				}
			}
		}
	}
	//We can also form the answer after creating the dp table in one more iteration
	return ans;

}
int lcs(string s, string t)
{
	int m = s.size();
	int n = t.size();
	vector<vector<int>> dp(m+1,vector<int> (n+1,-1)); //in tabulation we right shift indices to handle negative indices 
	return f(m,n,s,t,dp);
}