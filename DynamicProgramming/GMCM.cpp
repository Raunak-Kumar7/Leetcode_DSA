//Recursion Solution
    int f(int i, int j, int n, int arr[])
    {
        if(i==j) //single matrix left -->no operations
            return 0;
        int mini = INT_MAX;
        for(int k=i;k<j;k++)
        {
            int operations = arr[k]*arr[i-1]*arr[j] + f(i,k,n,arr) + f(k+1,j,n,arr);
            mini = min(mini,operations);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return f(1,N-1,N,arr);
    }


//Memoized Solution
    int f(int i, int j, int n, int arr[],vector<vector<int>>& dp)
    {
        if(i==j) //single matrix left -->no operations
            return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];  //S3
        for(int k=i;k<j;k++)
        {
            int operations = arr[k]*arr[i-1]*arr[j] + f(i,k,n,arr,dp) + f(k+1,j,n,arr,dp);
            mini = min(mini,operations);
        }
        return dp[i][j] = mini; //S2
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        //Number of changing variable = 2 both vary from 0--N-1
        vector<vector<int>> dp(N, vector<int> (N,-1));  //S1
        return f(1,N-1,N,arr,dp);
    }



    //Tabulation Solution (opposite of recursion tree)
    int f(int n, int arr[],vector<vector<int>>& dp)
    {
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        for(int i=n-1;i>=1;i--)
        {
            for(int j = i+1;j<n;j++) //j is always on right of i --> i+1
            {
                int mini = INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int operations = arr[k]*arr[i-1]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini,operations);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1]; //Initially we had this problem in recursion
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        //Number of changing variable = 2 both vary from 0--N-1
        vector<vector<int>> dp(N, vector<int> (N,-1));  
        return f(N,arr,dp);
    }

