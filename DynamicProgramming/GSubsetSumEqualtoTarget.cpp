    //Subset Sum Problem DP on Subsequences
    //Recursive
    //We can also add a B.C. if(sum==0) return true; this will better the T.C. but it is not neccessary
    bool f(int i,vector<int> arr, int sum )
    {
        if(i==0)
            return (arr[0]==sum);
        int nottake = f(i-1,arr,sum);
        int take = false;
        if(arr[i]<=sum) 
            take = f(i-1,arr,sum-arr[i]);
        return (take || nottake);
        
    }
    bool isSubsetSum(vector<int> arr, int sum){
        // code here 
        int n = arr.size();
        return f(n-1,arr,sum);
    }


//Subset Sum Problem DP on Subsequences
    //Memoized
    bool f(int i,vector<int> arr, int sum, vector<vector<int>>& dp)
    {
        if(i==0)
            return (arr[0]==sum);
        if(dp[i][sum]!=-1) return dp[i][sum]; //S3
        int nottake = f(i-1,arr,sum,dp);
        int take = false;
        if(arr[i]<=sum) 
            take = f(i-1,arr,sum-arr[i],dp);
        return dp[i][sum] = (take || nottake); //S2
        
    }
    bool isSubsetSum(vector<int> arr, int sum){
        // changing parameters --> i,sum
        //i varies from 0-n-1 and sum varies from 0-sum
        //Initialise -1 in memoisation
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1)); //S1
        return f(n-1,arr,sum,dp);
    }


    //Tabulation (Bottom Up of Recursive Tree)
    bool f(int n,vector<int> arr, int sum, vector<vector<bool>>& dp)
    {
        //B.C. --> Initialisation
        if(arr[0]<=sum) dp[0][arr[0]] = true; //first check if arr[0]<=sum else index out of bound
        for(int i=0;i<n;i++) dp[i][0] = true; //if sum is 0 we can always make it by not taking any coin
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int nottake = dp[i-1][j];
                int take = false;
                if(arr[i]<=j)
                    take = dp[i-1][j-arr[i]];
                dp[i][j] = (take||nottake);
            }
        }
        return dp[n-1][sum];  //We want to check with n elements (0-n-1) can we make sum
        
    }
    bool isSubsetSum(vector<int> arr, int sum){
        // changing parameters --> i,sum
        //i varies from 0-n-1 and sum varies from 0-sum
        //bool dp array for tabulation
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool> (sum+1,false)); //S1
        return f(n,arr,sum,dp);
    }



    //In this we can not do only 1 1D array space optimisation because we want dp[i-1][j-arr[i]] which means 
    //we require entire of previous row
    //Tabulation --> Space Optimisation (Bottom Up of Recursive Tree)
    bool f(int n,vector<int> arr, int sum)
    {
        //B.C. --> Initialisation
        vector<bool> prev(sum+1,false);
        //Init-1 
        if(arr[0]<=sum) prev[arr[0]] = true;
        prev[0] = true;
        
        for(int i=1;i<n;i++)
        {
            vector<bool> curr(sum+1,false);
            //Init 2
            curr[0] = true;//if sum is 0 we can always make it by not taking any coin
            for(int j=1;j<=sum;j++)
            {
                
                int nottake = prev[j];
                int take = false;
                if(arr[i]<=j)
                    take = prev[j-arr[i]];
                curr[j] = (take||nottake);
            }
            prev = curr;
        }
        return prev[sum];  //We want to check with n elements (0-n-1) can we make sum
    }
    bool isSubsetSum(vector<int> arr, int sum){
        // changing parameters --> i,sum
        //i varies from 0-n-1 and sum varies from 0-sum
        int n = arr.size();
        return f(n,arr,sum);
    }