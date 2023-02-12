//Try out all possibilities
    //Recursion Approach T.C O(n^n)
    int f(int i,int n, vector<int>& nums)
    {
        if(i>=n-1) //Reached Destination Base Case
            return true;
        if(nums[i]==0)
            return false; //can not go further
        bool ans = false;
        for(int ind = 1; ind<=nums[i];ind++)
        {
            ans = ans||f(i+ind,n,nums);
        }
        return ans;
    }
    bool canJump(vector<int>& nums) {
        //Starting point is fixed ending is not so start with starting point
        int n = nums.size();
        return f(0,n,nums);
    }


//Memoization Approach
    //We take int dp array instead of bool because in bool we have only 2 values so we can not initialise with -1
    //T.C. O(n^2) S.C O(n +n)
    int f(int i,int n, vector<int>& nums, vector<int>& dp)
    {
        if(i>=n-1) //Reached Destination Base Case
            return true;
        if(nums[i]==0)
            return false; //can not go further
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        for(int ind = 1; ind<=nums[i];ind++)
        {
            ans = ans||f(i+ind,n,nums,dp);
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int>& nums) {
        //Changing Variables --> i
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,n,nums,dp);
    }


//Try out all possibilities
    //Recursion Approach
    int f(int i,int n, vector<int>& nums)
    {
        if(i>=n-1) //Reached Destination Base Case
            return true;
        if(nums[i]==0)
            return false; //can not go further
        bool ans = false;
        for(int ind = 1; ind<=nums[i];ind++)
        {
            ans = ans||f(i+ind,n,nums);
        }
        return ans;
    }
    bool canJump(vector<int>& nums) {
        //Starting point is fixed ending is not so start with starting point
        int n = nums.size();
        return f(0,n,nums);
    }

//////////////////
//All DP approaches give TLE

//Seen -- revise
    //Greedy approach works (dp does not bcz constraints)
    bool canJump(vector<int>& nums) {
        //in greedy we pick the local optimum i.e. if at index i value is 5 so i check in next 5 indexes which value can take me farthest
        int n = nums.size();
        if(n==1) return true;
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi-1,nums[i]); //Max steps left to take
            if(maxi==0 && i!=n-1) //if steps left = 0 and not standing on last index --> not possible
                return false;
        }
        return true;
    }