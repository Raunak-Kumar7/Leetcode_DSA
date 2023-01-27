//Recursive Approach (Gives Tle)
int uniquePaths(int m, int n) {
        if(m==1||n==1)
            return 1;
        else
            return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }


//Dynamic Programming

int uniquePaths(int m, int n) {
        int arr[m+1][n+1];
        if(m==1||n==1)
            return 1;
            //Initialization
        for(int i=0;i<m+1;i++)
        {
             for(int j=0;j<n+1;j++)
             {
                   if(i==0||j==0)
                       arr[i][j]=0;
                   if(i==1||j==1)
                       arr[i][j]=1;
             }
        }
        for(int i=2;i<m+1;i++)
        {
            for(int j=2;j<n+1;j++)
            {
                arr[i][j]=arr[i-1][j]+arr[i][j-1];  
             }
        }
        return arr[m][n];
    }
