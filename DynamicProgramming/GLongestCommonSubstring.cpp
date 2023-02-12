//Same As LCS 
    //Recursion Approach
    int f(int i, int j, string& s1, string& s2, int ans)
    {
        if(i<0 || j<0)
            return ans;
        if(s1[i]==s2[j])
            ans = f(i-1,j-1,s1,s2,ans+1);
        ans = max(ans, max(f(i,j-1,s1,s2,0),f(i-1,j,s1,s2,0))); //if not picking ans reset to 0
        return ans;
    }
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        //To store All Time max bcs longest common substring can also be found in bw
        return f(m-1,n-1,S1,S2,0);
    }



    //Tabulation Approach --> LCS
    int f(string s1, string s2, int m, int n, vector<vector<int>>& dp)
    {
        int maxi = 0;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if(s1[i-1]==s2[j-1]) //right shift by 1
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                        maxi = max(maxi,dp[i][j]); //Longest substring can also be found within the string not neccessarily at end
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return maxi;
    }
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        // your code here
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return f(S1,S2,m,n,dp);
    }


    //Space Optimisation Approach --> LCS
    int f(string s1, string s2, int m, int n)
    {
        //We only require one previous row
        vector<int> prev(n+1,0);
        int maxi = 0;
        for(int i=0;i<=m;i++)
        {
            vector<int> curr(n+1,-1);
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    curr[j] = 0;
                else
                {
                    if(s1[i-1]==s2[j-1]) //right shift by 1
                    {
                        curr[j] = 1 + prev[j-1];
                        maxi = max(maxi,curr[j]); //Longest substring can also be found within the string not neccessarily at end
                    }
                    else
                    {
                        curr[j] = 0;
                    }
                }
            }
            prev = curr;
        }
        return maxi;
    }
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        // your code here
        return f(S1,S2,m,n);
    }
