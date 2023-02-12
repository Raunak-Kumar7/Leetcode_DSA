    //for length m+n -LCS()
    //print scs code,same as print lcs except also print non diagonal char
    //Tabulation Approach directly
    string f(int m, int n, string& str1, string& str2, vector<vector<int>>& dp)
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
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        //Dp Table created
        string ans = "";
        int r = m, c = n;
        while(r>0 && c>0)
        {
            if(str1[r-1]==str2[c-1]) // index right shift by 1
            {
                ans+=str1[r-1];
                r--;
                c--;
            }
            else if(dp[r][c-1]>dp[r-1][c]) //left is greater
            {
                ans+=str2[c-1];
                c--;
            }
            else  //up is greater
            {
                ans+=str1[r-1];
                r--;
            }
        }
        //copy the remaining strings if any
        while(r>0)
        {
            ans+=str1[r-1];
            r--;
        }
        while(c>0)
        {
            ans+=str2[c-1];
            c--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        return f(m,n,str1,str2,dp);
        
    }