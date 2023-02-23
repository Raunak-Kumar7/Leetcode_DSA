    //Equal Subset sum is only possible when sum is even
    //Question is same as subset sum equal to target
    //here target will be sum(nums)/2 becuase then both subsets will be equal
    
    //Recursive Approach
    //We can also add a B.C. if(sum==0) return true; this will better the T.C. but it is not neccessary
    int f(int i, vector<int>& nums, int sum)
    {
        if(i==0) return (nums[0]==sum); // if only 1 element is left then only 1 possible case
        
        int nottake = f(i-1,nums,sum);
        int take = false;
        if(nums[i]<=sum) take = f(i-1,nums,sum-nums[i]);
        return (take||nottake);
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        
        sum/=2;
        return f(n-1,nums,sum);
    }


    //Equal Subset sum is only possible when sum is even
    //Question is same as subset sum equal to target
    //here target will be sum(nums)/2 becuase then both subsets will be equal
    
    //Memoized Approach
    //We can also add a B.C. if(sum==0) return true; this will better the T.C. but it is not neccessary
    int f(int i, vector<int>& nums, int sum, vector<vector<int>>& dp)
    {
        if(i==0) return (nums[0]==sum); // if only 1 element is left then only 1 possible case
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nottake = f(i-1,nums,sum,dp);
        int take = false;
        if(nums[i]<=sum) take = f(i-1,nums,sum-nums[i],dp);
        return dp[i][sum] = (take||nottake); //S2
         
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        
        sum/=2;
        //parameters vary from i- 0,n-1   sum 0,sum
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return f(n-1,nums,sum,dp);
    }


//Many times Tabulation takes more time than memoization even though both have worst case as O(nxm)
//This is becuase in tabulation it has to visit all the states in the dp array to get dp[n-1][m-1]
//Whereas in memoisation it goes to only those states which are required


    //Tabulation Approach
    int f(int n, vector<int>& nums, int sum, vector<vector<bool>>& dp)
    {
        //B.C. --> Initialisation
        for(int i=0;i<n;i++) dp[i][0] = true; //if sum is 0 it can be formed by not taking any coins 
        if(nums[0]<=sum) dp[0][nums[0]] = true; 
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool nottake = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j] = (take||nottake);
            }
        }
        return dp[n-1][sum]; //we want to check if we can form sum with all n elements 0--n-1
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        
        sum/=2;
        //parameters vary from i- 0,n-1   sum 0,sum
        //Tabulation dp --> bool array
        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
        return f(n,nums,sum,dp);
    }



    //Tabulation Approach --> Space Optimisation
    int f(int n, vector<int>& nums, int sum)
    {
        //B.C. --> Initialisation
        //we only require 1 previous row of Dp array, we cant do 1 1D array optimisation because we need entire previous row dp[i-1][j-nums[i]];
        vector<bool> prev(sum+1,false);
        prev[0] = true;
        if(nums[0]<=sum) prev[nums[0]] = true;  //BC
        
        for(int i=1;i<n;i++)
        {
            vector<bool> curr(sum+1, false);
            curr[0] = true; //sum 0 can be formed anytime //BC
            for(int j=1;j<=sum;j++)
            {
                bool nottake = prev[j];
                bool take = false;
                if(nums[i]<=j) take = prev[j-nums[i]];
                curr[j] = (take||nottake);
            }
            prev = curr;
        }
        return prev[sum]; //we want to check if we can form sum with all n elements 0--n-1
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        
        sum/=2;
        //parameters vary from i- 0,n-1   sum 0,sum
        //Tabulation dp --> bool array
        return f(n,nums,sum);
    }


