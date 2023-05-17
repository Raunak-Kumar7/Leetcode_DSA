// direct 
    // Tabulation Approach
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        //right most column can not take any step --> value = 0
        for(int j=n-2;j>=0;j--)    //filling from right
        {
            for(int i=0;i<m;i++)
            {
                int ur = 0;
                int r  = 0;
                int dr = 0;
                if(i-1>=0 && grid[i-1][j+1]>grid[i][j])
                    ur = dp[i-1][j+1]+1;
                if(grid[i][j+1]>grid[i][j])
                    r = dp[i][j+1]+1;
                if(i+1<m && grid[i+1][j+1]>grid[i][j])
                    dr = dp[i+1][j+1]+1;
                
                if(ur==0 &&r==0 &&dr==0) //new sequence
                    dp[i][j] = 0;
                else
                    dp[i][j] = max(ur,max(r,dr));
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++)//we always have to start from the first column so search for ans only in first columns
        {
            ans = max(ans,dp[i][0]);
        }
        return ans;
    }