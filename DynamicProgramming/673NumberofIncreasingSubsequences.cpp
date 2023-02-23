    //Question can be implemented using LIS Tabulation 2 approach using a cnt vector
    int f(int n , vector<int>& nums)
    {
        vector<int> dp(n,1);
        vector<int> cnt(n,1); //We need to update the count array when we found more elements making same length
        int maxi = 1;
        int count;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    maxi = max(maxi,dp[i]);
                    cnt[i] = cnt[j];  //New max length found so cnt[i] = cnt[j] reset
                }
                else if(nums[j]<nums[i] && dp[j] + 1 == dp[i]) //same max length found so increase the cnt
                {
                    cnt[i] = cnt[i] + cnt[j] ;
                }
            }
        }
        //There can be multiple LIS of same length i.e. in dp array we can have multiple maxi ---> we need to add the cnts
        int maxcount = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
                maxcount+=cnt[i];
        }
        return maxcount;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f(n,nums);
        
    }