  //question is similar to find target sum 
  //to get min diff we need target as close as possible to sum(arr)/2
  //Tabulation approach 
    int f(int n, int arr[],vector<vector<bool>>& dp, int sum)
    {
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(arr[0]<=sum) dp[0][arr[0]] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool nottake = dp[i-1][j];
                bool take = false;
                if(arr[i]<=j) take = dp[i-1][j-arr[i]];
                dp[i][j] = take||nottake;
            }
        }
        //We need to find the sum in the last row which is as close as sum/2
        int S1 = 0;
        for(int j=sum/2;j>=0;j--)
        {
            if(dp[n-1][j]==true)
            {
                S1 = j;
                break;
            }
        }
        int S2 = sum - S1;
        return (abs(S1-S2));
        
    }
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr,arr+n,0);
	    //index varies from 0-n-1 and 0 - sum
	    
	    vector<vector<bool>> dp(n, vector<bool> (sum+1,false));
	    return f(n,arr,dp,sum);
	}


  //Tabulation approach --> space optimisation
    int f(int n, int arr[], int sum)
    {
        //We only 1 row previous (1 entire row is needed so 2 1D array optimisation)
        vector<bool> prev(sum+1,false);
        prev[0] = true;
        if(arr[0]<=sum) prev[arr[0]] = true;

        for(int i=1;i<n;i++)
        {
            vector<bool> curr(sum+1,false);
            curr[0] = true;
            for(int j=1;j<=sum;j++)
            {
                bool nottake = prev[j];
                bool take = false;
                if(arr[i]<=j) take = prev[j-arr[i]];
                curr[j] = take||nottake;
            }
            prev = curr;
        }
        //We need to find the sum in the last row which is as close as sum/2
        int S1 = 0;
        for(int j=sum/2;j>=0;j--)
        {
            if(prev[j]==true)
            {
                S1 = j;
                break;
            }
        }
        int S2 = sum - S1;
        return (abs(S1-S2));
        
    }
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr,arr+n,0);
	    //index varies from 0-n-1 and 0 - sum
	    
	    return f(n,arr,sum);
	}