//We need to check all paths and check if their sum%k==0
    //all paths -> recursion
    //Approach 1: recursion
    int f(int i, int j, int m, int n, int k, vector<vector<int>>& grid, int sum)
    {
        //Base Case 1: 
        if(i==0 && j==0) //reached destination BC
        {
            sum+=grid[0][0];
            if(sum%k==0)
                return 1; //Count number of paths
            else
                return 0;
        }
        //Out of bound base condition
        if(i<0 || j<0) //Dont Alter sum
            return 0;
        int up = f(i-1,j,m,n,k,grid,(sum+grid[i][j]));
        int left = f(i,j-1,m,n,k,grid,(sum+grid[i][j]));
        return up+left;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        //mxn matrix
        return f(m-1,n-1,m,n,k,grid,0); // 3 values are changing i.e. indexes and sum --> 3d dp
    }


    //Approach 2: Memoization
    int f(int i, int j, int m, int n, int k, vector<vector<int>>& grid, int sum, vector<vector<vector<int>>>& dp)
    {
        //Base Case 1: 
        if(i==0 && j==0) //reached destination BC
        {
            sum+=grid[0][0];
            if(sum%k==0)
                return 1; //Count number of paths
            else
                return 0;
        }
        //Out of bound base condition
        if(i<0 || j<0) //Dont Alter sum
            return 0;
        if(dp[i][j][sum%k]!=-1) return dp[i][j][sum%k]; //S3
        int up = f(i-1,j,m,n,k,grid,(sum%k+grid[i][j]%k)%k,dp);
        int left = f(i,j-1,m,n,k,grid,(sum%k+grid[i][j]%k)%k,dp);
        return dp[i][j][sum%k] = ((up%1000000007)+(left%1000000007))%1000000007; //S2
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        //mxn matrix
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (k,-1))); //S1 //remainder can vary from 0--k-1
        //3d dp where 3rd value is number of paths with remainder = value
        int x = f(m-1,n-1,m,n,k,grid,0,dp);
        return x; 
    }

    