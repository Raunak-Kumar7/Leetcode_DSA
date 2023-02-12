//We always reach last position in this ques

//Recursion Approach -> find minimum out of all possible ways 
    //return type int --> long long int
    long long int f(int i, int n,vector<int>& nums)
    {
        if(i>=n-1) return 0; //no more jumps reqd to take
        long long int mini = INT_MAX;
        for(int ind = 1;ind<=nums[i];ind++)
        {
            mini = min(mini,1 + f(i+ind,n,nums));
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        return f(0,n,nums);
    }



//Memoisation Approach -> find minimum out of all possible ways 
    //return type int --> long long int
    long long int f(int i, int n,vector<int>& nums,vector<int>& dp)
    {
        if(i>=n-1) return 0; //no more jumps reqd to take
        if(dp[i]!=-1) return dp[i];
        long long int mini = INT_MAX;
        for(int ind = 1;ind<=nums[i];ind++)
        {
            mini = min(mini,1 + f(i+ind,n,nums,dp));
        }
        return dp[i] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        //changing variable i
        vector<int> dp(n,-1);
        return f(0,n,nums,dp);
    }


//Tabulation Approach 
    //return type int --> long long int
    long long int f(int n,vector<int>& nums,vector<long long int>& dp)
    {
        for(int i = n-1;i>=0;i--)
        {
            if(i==n-1) //Initialisation
                dp[i] = 0;
            else
            {
                long long int mini = INT_MAX;
                for(int ind = 1;ind<=nums[i];ind++)
                {
                    if(i+ind<n)
                        mini = min(mini,1 + dp[i+ind]);
                }
                dp[i] = mini;   
            }
        }
        return dp[0];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        //changing variable i
        vector<long long int> dp(n,-1);
        return f(n,nums,dp);
    }


//Seen
