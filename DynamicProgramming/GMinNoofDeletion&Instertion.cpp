// convert str1 --> str2

	//Recursive Approach (m+n-2LCS())
	int f(int i, int j, string& str1, string& str2)
	{
	    if(i<0 || j<0)
	        return 0;
	    if(str1[i]==str2[j])
	        return 1 + f(i-1,j-1,str1,str2);
	    else
	        return 0 + max(f(i-1,j,str1,str2),f(i,j-1,str1,str2));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    return (m + n - 2*f(m-1,n-1,str1,str2));
	} 

	//Memoized Approach (m+n-2LCS())
	int f(int i, int j, string& str1, string& str2, vector<vector<int>>& dp)
	{
	    if(i<0 || j<0)
	        return 0;
	       if(dp[i][j]!=-1) return dp[i][j];
	    if(str1[i]==str2[j])
	        return dp[i][j] = 1 + f(i-1,j-1,str1,str2,dp);
	    else
	        return dp[i][j] = 0 + max(f(i-1,j,str1,str2,dp),f(i,j-1,str1,str2,dp));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    vector<vector<int>> dp(m,vector<int> (n,-1));
	    return (m + n - 2*f(m-1,n-1,str1,str2,dp));
	} 


	//Tabulation Approach (m+n-2LCS())
	int f(int m, int n, string& str1, string& str2, vector<vector<int>>& dp)
	{
	    for(int i=0;i<=m;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0 || j==0)
	                dp[i][j] = 0;
	            else
	            {
	                if(str1[i-1]==str2[j-1])
	                    dp[i][j] = 1 + dp[i-1][j-1];
	                else
	                    dp[i][j] = 0 + max(dp[i][j-1],dp[i-1][j]);
	            }
	        }
	    }
	   return dp[m][n];
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    vector<vector<int>> dp(m+1,vector<int> (n+1,-1)); //Right shift by 1 in tabulation
	    return (m + n - 2*f(m,n,str1,str2,dp));
	}


	//Space Optimisation Approach (m+n-2LCS())
	int f(int m, int n, string& str1, string& str2)
	{
	    //We only need one previous row
	    vector<int> prev(n+1,0);
	    for(int i=0;i<=m;i++)
	    {
	        vector<int> curr(n+1,-1);
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0 || j==0)
	                curr[j] = 0;
	            else
	            {
	                if(str1[i-1]==str2[j-1])
	                    curr[j] = 1 + prev[j-1];
	                else
	                    curr[j] = 0 + max(curr[j-1],prev[j]);
	            }
	        }
	        prev = curr;
	    }
	   return prev[n];
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    return (m + n - 2*f(m,n,str1,str2));
	} 