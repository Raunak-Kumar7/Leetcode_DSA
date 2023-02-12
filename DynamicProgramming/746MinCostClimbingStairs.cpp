//Question is similar to Triangle where starting point is variable and ending point is fixed
    int f(int i,int n , vector<int>& cost)
    {
        if(i>=n) //Reached destination
            return 0;
        return cost[i] + min(f(i+1,n,cost),f(i+2,n,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //find min cost for both starting point
        int n = cost.size();
        return min(f(0,n,cost),f(1,n,cost));
    }


//Memoized Solution
    //Question is similar to Triangle where starting point is variable and ending point is fixed
    int f(int i,int n , vector<int>& cost, vector<int> dp)
    {
        if(i>=n) //Reached destination
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(f(i+1,n,cost,dp),f(i+2,n,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //find min cost for both starting point
        //one Changing variable
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(f(0,n,cost,dp),f(1,n,cost,dp)); 
    }


//Tabulation Solution (Bottom up of recusrisive tree)
    int f(int x, int n , vector<int>& cost, vector<int> dp)
    {
        for(int i = n+1;i>=x;i--)
        {
            if(i==n || i==n+1)
                dp[i] = 0;
            else
            {
                dp[i] = cost[i] + min(dp[i+1] , dp[i+2]);
            }
        }
        return dp[x];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //find min cost for both starting point
        //one Changing variable
        int n = cost.size();
        vector<int> dp(n+2,-1); //n+2 because we acces i+1 and i+2
        return min(f(0,n,cost,dp),f(1,n,cost,dp)); 
    }


//Space Optimisation Solution (Bottom up of recusrisive tree)
    //We only need 2 states ahead
    int f(int x, int n , vector<int>& cost, vector<int> dp)
    {
        int ahead2 = 0;
        int ahead = 0;
        for(int i = n+1;i>=x;i--)
        {
            int curr = -1;
            if(i==n || i==n+1)
                curr = 0;
            else
            {
                curr = cost[i] + min(ahead , ahead2);
            }
            ahead2 = ahead;
            ahead = curr;
        }
        return ahead;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //find min cost for both starting point
        //one Changing variable
        int n = cost.size();
        vector<int> dp(n+2,-1); //n+2 because we acces i+1 and i+2
        return min(f(0,n,cost,dp),f(1,n,cost,dp)); 
    }