//Question is an extension on Unique Paths 1
    //Approach 1: Recursion (top down) T.C(2^(m*n)) S.C. O(m-1 + n-1)
    int f(int i, int j, vector<vector<int>>& grid)
    {
        if(i==0 && j==0) //Base Condition Reached Destination
            return grid[0][0];
        if(i<0 || j<0)  //Base Condition Out of Bound
            return 1e8; // Because we are finding Minimum we need to return a large value to not consider this path
        int up = grid[i][j] + f(i-1,j,grid);
        int left = grid[i][j] + f(i,j-1,grid);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return f(m-1,n-1,grid);
    }

//Approach 2: Memoized (top down)  T.C. O(m*n) S.C. O(m*n + path length m-1+n-1)
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==0 && j==0) //Base Condition Reached Destination
            return grid[0][0];
        if(i<0 || j<0)  //Base Condition Out of Bound
            return 1e8; // Because we are finding Minimum we need to return a large value to not consider this path
        if(dp[i][j]!=-1) return dp[i][j];  //S3
        int up = grid[i][j] + f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);
        return dp[i][j] = min(up,left);  //S2
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1)); //S1
        return f(m-1,n-1,grid,dp);
        
    }

//Approach 2: Tabulation (Bottom up of recursive tree) T.C. O(m*n) S.C O(m*n)
    int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) //BC 1 //S2
                    dp[i][j] = grid[0][0];
                else
                {
                    int up = 1e8;
                    int left = 1e8;
                    if(i>0) up = grid[i][j] + dp[i-1][j]; //BC 2 Handled Here //S3
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up,left);   
                }
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1)); //S1
        return f(m,n,grid,dp);
    }


    //Approach 2: Tabulation --> Space Optimisation (Bottom up of recursive tree) T.C O(m*n) S.C O(n)
    int f(int m, int n, vector<vector<int>>& grid)
    {
        vector<int> prev(n,1e8); //Base Case2: as it is min we initialise it with a large number
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) //BC 1 //S2
                    curr[j] = grid[0][0];
                else
                {
                    int up = grid[i][j] + prev[j];
                    int left = 1e8;
                    if(j>0) left = grid[i][j] + curr[j-1];
                    curr[j] = min(up,left);    //We only need 1 previous row of dp array
                }
            }
            prev = curr;
        }
        return prev[n-1]; //prev and curr contain same 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return f(m,n,grid);
    }