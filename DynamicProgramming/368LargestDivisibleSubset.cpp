    //same as lis if we sort the array 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //Using tabulation 2 approach to solve 
        //to print LIS using tabulation 2 we used a hash variable
        sort(nums.begin(),nums.end());  //we sort bcz order doesnt matter and by sorting we can convert the problem to LIS as all are in increasing order
        int n = nums.size();
        vector<int> dp(n);
        vector<int> hash(n); 
        vector<int> ans;
        for(int i=0;i<n;i++) dp[i] = 1;
        for(int i=0;i<n;i++) hash[i] = i;//Fill hash with current index if not updating
        int maxi = 1;
        int maxipos = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 )//condition changed acc to question , not hcecking the other condition becuase array is sorted so j%i==0 not possible
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                    if(dp[i]>maxi)
                    {
                        maxi = dp[i];
                        maxipos = i;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<hash[i]<<" ";
        ans.push_back(nums[maxipos]);
        while(--maxi)
        {
            maxipos = hash[maxipos];
            ans.push_back(nums[maxipos]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }