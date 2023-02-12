    //s1-->s2 (here s2 = reverse(s1))
    //no. of insertions = no. of deletions =  n - LPS()

    //Recursion approach
    int f(int i, int j, string& s, string& t)
    {
        if(i<0 || j<0)
            return 0;
        if(s[i]==t[j])
            return 1 + f(i-1,j-1,s,t);
        else
            return 0 + max(f(i-1,j,s,t) , f(i,j-1,s,t));
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        return ( n - f(n-1,n-1,s,t));
    }


    //Memoized Approach
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
        else
            return dp[i][j] = 0 + max(f(i-1,j,s,t,dp) , f(i,j-1,s,t,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return ( n - f(n-1,n-1,s,t,dp));
    }


    //Tabulation Approach
    int f(int n, string& s, string& t, vector<vector<int>>& dp)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if(s[i-1]==t[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));  //Tabulation right shift by 1
        return ( n - f(n,s,t,dp));
    }



    //Space Optimisation Approach
    int f(int n, string& s, string& t)
    {
        //we only need a row prev
        vector<int> prev(n+1,0);
        for(int i=0;i<=n;i++)
        {
            vector<int> curr(n+1,-1);
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    curr[j] = 0;
                else
                {
                    if(s[i-1]==t[j-1])
                        curr[j] = 1 + prev[j-1];
                    else
                        curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        return ( n - f(n,s,t));
    }