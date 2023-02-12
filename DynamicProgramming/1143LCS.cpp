    //Recursion Approach
    int f(int i, int j, string &text1, string &text2)
    {
        if(i<0 || j<0)
            return 0;
        if(text1[i]==text2[j]) //If character matched, add 1 to length
            return 1 + f(i-1,j-1,text1,text2);
        else
            return 0 + max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        return f(m-1,n-1,text1,text2);
    }


   //Memoization Approach
    int f(int i, int j, string &text1, string &text2, vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) //If character matched, add 1 to length
            return dp[i][j] = 1 + f(i-1,j-1,text1,text2,dp);
        else
            return dp[i][j] = 0 + max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //changing parameters = 2 , i,j 0-m-1 ,0,n-1
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,text1,text2,dp);
    }


    //Tabulation Approach(Reverse of Recursion Tree)
    int f(int m, int n, string &text1, string &text2, vector<vector<int>>& dp)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0) //Initialisation
                    dp[i][j] = 0;
                else
                {//right shifted index by 1
                    if(text1[i-1]==text2[j-1]) //If character matched, add 1 to length
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //changing parameters = 2 , i,j 0-m-1 ,0,n-1
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1)); //In tabulation we right shift by 1 to handle negative indices
        return f(m,n,text1,text2,dp);
    }


    //Tabulation Approach --> Space Optimisation(Reverse of Recursion Tree)
    int f(int m, int n, string &text1, string &text2)
    {
        //We Only need one row previous
        vector<int> prev(n+1,0);
        for(int i=0;i<=m;i++)
        {
            vector<int> curr(n+1,-1); 
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0) //Initialisation
                    curr[j] = 0;
                else
                {//right shifted index by 1
                    if(text1[i-1]==text2[j-1]) //If character matched, add 1 to length
                        curr[j] = 1 + prev[j-1];
                    else
                        curr[j] = 0 + max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n]; //prev = curr
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //changing parameters = 2 , i,j 0-m-1 ,0,n-1
        return f(m,n,text1,text2);
    }