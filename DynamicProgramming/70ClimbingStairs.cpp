    //Recursive Solution
    int f(int n)
    {
        if(n<0) return 0;
        else if(n==1||n==0) return 1;
        return f(n-2) + f(n-1);
    }
    int climbStairs(int n) {
        return f(n);
    }


    //Memoization Solution
    int f(int n, vector<int>& dp)
    {
        if(n<0) return 0;
        else if(n==1||n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = f(n-2,dp) + f(n-1,dp);
    }
    int climbStairs(int n) {
        //changing parameter =1; 0->n
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }

    //Tabulation Solution (Bottom Up of Recursive Tree)
    int f(int n, vector<int>& dp)
    {
        for(int i=0;i<n+1;i++)
        {
            if(i==0 || i==1)  //Base Case
                dp[i] = 1;
            else //recurrence
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
    int climbStairs(int n) {
        //changing parameter =1; 0->n
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }

//Space Optimisation of Tabulation  (Bottom Up of Recursive Tree)
    int f(int n, vector<int>& dp)
    {
        int prev2 = 0;
        int prev = 0;
        for(int i=0;i<n+1;i++)
        {
            int curr = -1;
            //we only require previous 2 states
            if(i==0 || i==1)  //Base Case
                curr = 1;
            else //recurrence
            {
                curr = prev + prev2;
            }
            prev2 = prev;
            prev = curr;
        }
        return prev; //prev = curr at last step
    }
    int climbStairs(int n) {
        //changing parameter =1; 0->n
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
    