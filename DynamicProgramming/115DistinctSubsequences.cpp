//Count all ways -->Recursion
    int f(int i, int j, string& s, string& t)
    {
        if(j<0) return 1; //t has been made , s maybe finished or not
        if(i<0 && j>=0) return 0;  //t has not yet been made and s is finished
        if(s[i]==t[j]) //if char match Take Or wait for next
        {
            return f(i-1,j-1,s,t) + f(i-1,j,s,t); 
        }
        else //if character does not match
        {
            return f(i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        return f(m-1,n-1,s,t);
    }


    //Memoization
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp)
    {
        if(j<0) return 1; //t has been made , s maybe finished or not
        if(i<0 && j>=0) return 0;  //t has not yet been made and s is finished
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) //if char match Take Or wait for next
        {
            return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp); 
        }
        else //if character does not match
        {
            return dp[i][j] = f(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //Changing parameters 2 i,j
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,s,t,dp);
    }



    //Tabulation
    //with long long it is still giving RTE --> use double
    int f(int m, int n, string& s, string& t, vector<vector<double>>& dp)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0) dp[i][j] = 0; //t has not yet been made and s is finished
                    if(j==0) dp[i][j] = 1; //t has been made , s maybe finished or not 0,0 means both are finished
                }
                else
                {
                    if(s[i-1]==t[j-1])
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
                    
            }
        }
        return dp[m][n];
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //Changing parameters 2 i,j
        vector<vector<double>> dp(m+1,vector<double> (n+1,-1));  //Right shift index by 1
        return (int)f(m,n,s,t,dp);  // back to int
    }


    
    //Space Optimisation
    //with long long it is still giving RTE --> use double
    int f(int m, int n, string& s, string& t)
    {
        //We only need one previous row
        vector<double> prev(n+1,0);
        for(int i=0;i<=m;i++)
        {
            vector<double> curr(n+1,-1);
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0) curr[j] = 0; //t has not yet been made and s is finished
                    if(j==0) curr[j] = 1; //t has been made , s maybe finished or not 0,0 means both are finished
                }
                else
                {
                    if(s[i-1]==t[j-1])
                        curr[j] = prev[j-1] + prev[j];
                    else
                        curr[j] = prev[j];
                }
                    
            }
            prev = curr;
        }
        return prev[n];
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        //Changing parameters 2 i,j
        return (int)f(m,n,s,t);  // back to int
    }