    //Find LCS between s and reverse(s)
    //Recursive Approach
    int f(int i, int j, string& s, string& t)
    {
        if(i<0 || j<0)
            return 0;
        if(s[i]==t[j])
            return 1 + f(i-1,j-1,s,t);
        else
            return max(f(i-1,j,s,t),f(i,j-1,s,t));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        return f(n-1,n-1,s,t);
    }


    //Find LCS between s and reverse(s)
    //Memoized Approach
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
        else
            return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        //changing parameters i,j
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(n-1,n-1,s,t,dp);
    }


    //Find LCS between s and reverse(s)
    //Tabulation Approach
    int f(int n, string& s, string& t, vector<vector<int>>& dp)
    {
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if(s[i-1]==t[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        //changing parameters i,j
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1)); //right shift by 1
        return f(n,s,t,dp);
    }


    //Find LCS between s and reverse(s)
    //Space Optimised Approach
    int f(int n, string& s, string& t)
    {
        //We Only require one previous row
        vector<int> prev(n+1,0);
        for(int i=0;i<n+1;i++)
        {
            vector<int> curr(n+1,-1);
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    curr[j] = 0;
                else
                {
                    if(s[i-1]==t[j-1])
                        curr[j] = 1 + prev[j-1];
                    else
                        curr[j] = max(prev[j] , curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        //changing parameters i,j
        return f(n,s,t);
    }