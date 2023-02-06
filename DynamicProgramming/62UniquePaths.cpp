    //Approach 1: Recursive T.C. O(2^(m*n)) S.C. O(path length m-1 + n-1)
    int f(int i, int j)
    {
        if(i==0 && j==0) 
            return 1; //Count no. of ways
        if(i<0 || j<0)
            return 0;
        int up = f(i-1,j);
        int left = f(i,j-1);
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }

    //Approach 2: Memoization  T.C. O(m*n) S.C. O(m*n + length of path(m-1+n-1))
    int f(int i, int j,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) 
            return 1; //Count no. of ways
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j]; //S3
        int up = f(i-1,j,dp);
        int left = f(i,j-1,dp);
        return dp[i][j] = up+left; //S2
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1)); //S1
        return f(m-1,n-1,dp);
    }


    //Approach 3: Tabulation [Bottom Up of recursive tree]  T.C. O(m*n) S.C. O(m*n)
    int f(int m, int n, vector<vector<int>>& dp)
    {
        //S2 Base Condition -> Initialisation
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)//S3
            {
                if(i==0 && j==0)  //Base Case 1
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j]; //Base Case 2 handelled her
                    if(j>0) left = dp[i][j-1]; 
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1)); //S1
        return f(m,n,dp);
    }


    //Approach 4: Space Optimisation of Tabulation [Bottom Up of recursive tree]  T.C. O(m*n) S.C. O(n)
    int f(int m, int n)
    {
        //S2 Base Condition -> Initialisation
        vector<int> prev(n,0); 
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,-1);
            for(int j=0;j<n;j++)//S3
            {
                if(i==0 && j==0)  //Base Case 1
                    curr[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    // we can see we only need the previous row
                    up = prev[j]; 
                    if(j>0) left = curr[j-1]; 
                    curr[j] = up+left;
                }
            }
            prev = curr; 
        }
        return prev[n-1];//at last we updates prev = curr
    }
    int uniquePaths(int m, int n) {
        return f(m,n);
    }

