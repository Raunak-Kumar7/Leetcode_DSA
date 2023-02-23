    //Function to return max value that can be put in knapsack of capacity W.
    //RecursiveApproach
    int f(int i, int W, int wt[], int val[])
    {
        if(i==0)
        {
            if(wt[i]<=W) return val[i];  //if can pick then do pick to maximize
            else return 0;
        }
        int notpick = f(i-1,W,wt,val);
        int pick = 0;
        if(wt[i]<=W)
            pick = val[i] + f(i-1,W-wt[i],wt,val);
        return max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return f(n-1,W,wt,val);
    }


    //Memoized Approach
    int f(int i, int W, int wt[], int val[],vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(wt[i]<=W) return val[i];  //if can pick then do pick to maximize
            else return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int notpick = f(i-1,W,wt,val,dp);
        int pick = 0;
        if(wt[i]<=W)
            pick = val[i] + f(i-1,W-wt[i],wt,val,dp);
        return dp[i][W] = max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //2 parameters vary i 0-n-1, and W 0->W
       vector<vector<int>> dp(n,vector<int> (W+1, -1));
       return f(n-1,W,wt,val,dp);
    }


        //Tabulation Approach
    int f(int n, int W, int wt[], int val[],vector<vector<int>>& dp)
    {
        for(int j=0;j<=W;j++)
        {
            if(wt[0]<=j) dp[0][j] = val[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                int notpick = dp[i-1][j];
                int pick = 0;
                if(wt[i]<=j)
                    pick = val[i] + dp[i-1][j-wt[i]];
                dp[i][j] = max(pick,notpick);
            }
        }
        return dp[n-1][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //2 parameters vary i 0-n-1, and W 0->W
       //In tabulation initialise w 0
       vector<vector<int>> dp(n,vector<int> (W+1, 0));
       return f(n,W,wt,val,dp);
    }


    //Space Optimisation Approach
    int f(int n, int W, int wt[], int val[])
    {
        vector<int> prev(W+1,0); //prev[0] already initialised to 0
        for(int j=0;j<=W;j++)
        {
            if(wt[0]<=j) prev[j] = val[0];
        }
        for(int i=1;i<n;i++)
        {
            vector<int> curr(W+1,0);
            for(int j=1;j<=W;j++)
            {
                int notpick = prev[j];
                int pick = 0;
                if(wt[i]<=j)
                    pick = val[i] + prev[j-wt[i]];
                curr[j] = max(pick,notpick);
            }
            prev = curr;
        }
        return prev[W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //2 parameters vary i 0-n-1, and W 0->W
       //In tabulation initialise w 0
       return f(n,W,wt,val);
    }



    // 1 1D array Space Optimisation Approach
    int f(int n, int W, int wt[], int val[])
    {
        vector<int> prev(W+1,0); //prev[0] already initialised to 0
        for(int j=0;j<=W;j++)
        {
            if(wt[0]<=j) prev[j] = val[0];
        }
        for(int i=1;i<n;i++)
        {
            //vector<int> curr(W+1,0);
            //To do this we should run the w loop in opposite manner bcz we dont want to alter prev[j-wt[i]]
            for(int j=W;j>=1;j--)
            {
                int notpick = prev[j];
                int pick = 0;
                if(wt[i]<=j)
                    pick = val[i] + prev[j-wt[i]];
                prev[j] = max(pick,notpick);
                //curr[j] = max(pick,notpick);
            }
            //prev = curr;
        }
        return prev[W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //2 parameters vary i 0-n-1, and W 0->W
       //In tabulation initialise w 0
       return f(n,W,wt,val);
    }