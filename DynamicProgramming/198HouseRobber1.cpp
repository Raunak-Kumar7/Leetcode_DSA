//Question is same as Maximum Sum of Non Adjacent Elements GFG

//Solution 1: Recursive Solution //i.e. Top Down //Gives TLE O(2^n) O(n)
    int robber(vector<int>& nums, int n)//idx
    {
        if(n==0) //if we are standing at 0 means we did not pick 1--> so we should pick 0 to maximise
            return nums[0];
        if(n<0)
            return 0;
        int left = nums[n] + robber(nums,n-2);//Pick //edge case if n==1 ---> n-2 will give negative index
        int right = 0 + robber(nums,n-1); //Not Pick
        return max(left,right);
    }
    int rob(vector<int>& nums) {
        return robber(nums,nums.size()-1);
    }


//Solution 2: Memoized Solution //i.e. Top Down  O(n) O(2n)
    int robber(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n==0) //if we are standing at 0 means we did not pick 1--> so we should pick 0 to maximise
            return nums[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1) //Step3
            return dp[n];
        int left = nums[n] + robber(nums,n-2,dp);//Pick //edge case if n==1 ---> n-2 will give negative index
        int right = 0 + robber(nums,n-1,dp); //Not Pick
        return dp[n] = max(left,right); //Step2
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1); //Step1
        return robber(nums,n-1,dp);
    }



//Solution 3: Tabulation Solution //i.e. Bottom Up O(n) O(n)
    int robber(vector<int>& nums, int n, vector<int>& dp)
    {
        //Initialisation --> Step2
        dp[0] = nums[0]; //if we are standing at 0 means we did not pick 1--> so we should pick 0 to maximise
        int left,right;
        for(int i=1;i<=n;i++)
        {
            if(i-2<0) left = nums[i];  //Base condition 2 handled here
            else left = nums[i] + dp[i-2];//Pick
            right = 0 + dp[i-1]; //Not Pick
            dp[i] = max(left,right);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1); //Step1
        return robber(nums,n-1,dp);
    }


//Solution 4: Tabulation Solution Space Optimised(we only need dp[i-1],dp[i-2]) //i.e. Bottom Up
    int robber(vector<int>& nums, int n)
    {
        //Initialisation --> Step2
        int curr=nums[0],prev2,prev1;
        prev2 = 0;
        prev1 = nums[0]; //if we are standing at 0 means we did not pick 1--> so we should pick 0 to maximise
        int left,right;
        for(int i=1;i<=n;i++)
        {
            left = nums[i] + prev2;//Pick
            right = 0 + prev1; //Not Pick
            curr = max(left,right);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return robber(nums,n-1);
    }