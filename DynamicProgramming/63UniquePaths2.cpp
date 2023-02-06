//Question is same as Unique Paths 1 --> only 1 more condition has to be added
    //Approach 1 --> Recursive solution (Top Down) T.C. O(2^(m*n)) for every cell there is a possibility of 2 paths
    //S.C. O(path length m-1 + n-1)
    int f(vector<vector<int>>&a, int i, int j)
    {
        //Base Condition 
        if(i==0 && j==0 && a[i][j]==1) //edge case
            return 0;
        if(i==0 && j==0) //destination Base case
            return 1;
        if(i<0 || j<0) //out of bound base case
            return 0;
        if(a[i][j] == 1) //Obstacle base condition
            return 0;
        //recursive tree
        int up = f(a,i-1,j);
        int left = f(a,i,j-1);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return f(obstacleGrid,m-1,n-1);
    }

//Approach 2 --> Memoized solution (Top Down)  T.C. O(m*n) S.C O(m*n + path length m-1 + n-1)
    int f(vector<vector<int>>&a, int i, int j,vector<vector<int>>& dp)
    {
        //Base Condition 
        if(i==0 && j==0 && a[i][j]==1) //edge case
            return 0;
        if(i==0 && j==0) //destination Base case
            return 1;
        if(i<0 || j<0) //out of bound base case
            return 0;
        if(a[i][j] == 1) //Obstacle base condition
            return 0;
        //recursive tree
        if(dp[i][j]!=-1) return dp[i][j]; //S3
        int up = f(a,i-1,j,dp);
        int left = f(a,i,j-1,dp);
        return dp[i][j] = up+left; //S2
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));  //S1
        return f(obstacleGrid,m-1,n-1,dp);
    }


    //Approach 3 --> Tabulation solution (Bottom Up of Recursion tree) 
    //T.C O(m*n) S.C.O(m*n)
    int f(vector<vector<int>>&a, int m, int n,vector<vector<int>>& dp)
    {
        //Base Condition 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0 && a[i][j]==1) //S2 Base condition --> initialisation
                    dp[i][j] = 0;
                else if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(a[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));  //S1
        return f(obstacleGrid,m,n,dp);
    }


    //Approach 4 --> Tabulation solution->space optimisation (Bottom Up of Recursion tree) 
    //T.C O(m*n) S.C.O(n)
    int f(vector<vector<int>>&a, int m, int n)
    {
        //Base Condition 
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0 && a[i][j]==1) //S2 Base condition --> initialisation
                    curr[j] = 0;
                else if(i==0 && j==0)
                    curr[j] = 1;
                else if(a[i][j] == 1)
                    curr[j] = 0;
                else
                {
                    int up = 0;
                    int left = 0;
                    //we only require one previous row of dp array
                    up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up+left;
                }
            }
            prev = curr;
        }
        return prev[n-1]; //Updated prev with curr at last so both have same values
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return f(obstacleGrid,m,n);
    }