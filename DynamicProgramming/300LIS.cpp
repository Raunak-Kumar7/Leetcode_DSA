    //Recursive Approach
    int f(int idx, int previdx, int n, vector<int>& nums)
    {
        if(idx==n)
            return 0;
        if(previdx==-1 || nums[idx]>nums[previdx])
        {
            return max(1+f(idx+1,idx,n,nums),f(idx+1,previdx,n,nums));
        }
        else
        {
            return f(idx+1,previdx,n,nums);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f(0,-1,n,nums);
    }



    //Memoized Approach
    int f(int idx, int previdx, int n, vector<int>& nums,vector<vector<int>>& dp)
    {
        if(idx==n)
            return 0;
        if(dp[idx][previdx+1]!=-1)
            return dp[idx][previdx+1];
        if(previdx==-1 || nums[idx]>nums[previdx])
        {
            return dp[idx][previdx+1] = max(1+f(idx+1,idx,n,nums,dp),f(idx+1,previdx,n,nums,dp));
        }
        else
        {
            return dp[idx][previdx+1] = f(idx+1,previdx,n,nums,dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //Changing Parameters 2 idx 0->n-1  prevIdx = -1 -> n-2 but we right shift idx by 1 , in dp use dp[idx][previdx+1]
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,-1,n,nums,dp);
    }


//IMPORTANT RIGHT SHIFTING
 //Tabulation Approach
    int f(int n, vector<int>& nums, vector<vector<int>>& dp)
    {
        //initialisation separately
        for(int idx=n;idx>=0;idx--)
        {
            for(int previdx = n ;previdx>=0;previdx--)
            {
                if(idx==n)
                    dp[idx][previdx] = 0;
            }
        }
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int previdx = idx-1;previdx>=-1;previdx--)
            {
                if(previdx==-1 || nums[idx]>nums[previdx])
                    dp[idx][previdx+1] = max(1+dp[idx+1][idx+1],dp[idx+1][previdx+1]);
                else
                    dp[idx][previdx+1] = dp[idx+1][previdx+1];
            }
        }
        return dp[0][0];
    
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //Changing parameters idx, previdx
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return f(n,nums,dp);
    }



/////-- same tabulation code --
    //directly initialising dp to 0
    int f(int n, vector<int>& nums, vector<vector<int>>& dp)
    {
       
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int previdx = idx-1;previdx>=-1;previdx--)
            {
                if(previdx==-1 || nums[idx]>nums[previdx])
                    dp[idx][previdx+1] = max(1+dp[idx+1][idx+1],dp[idx+1][previdx+1]);
                else
                    dp[idx][previdx+1] = dp[idx+1][previdx+1];
            }
        }
        return dp[0][0];
    
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //Changing parameters idx, previdx
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        return f(n,nums,dp);
    }



    //Space Optimisation
    int f(int n, vector<int>& nums)
    {
       // we only need 1 row further idx+1
        vector<int> ahead(n+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            vector<int> curr(n+1,0);
            for(int previdx = idx-1;previdx>=-1;previdx--)
            {
                if(previdx==-1 || nums[idx]>nums[previdx])
                    curr[previdx+1] = max(1+ahead[idx+1],ahead[previdx+1]);
                else
                    curr[previdx+1] = ahead[previdx+1];
            }
            ahead = curr;
        }
        return ahead[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //Changing parameters idx, previdx
        return f(n,nums);
    }


//2nd tabulation method 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            dp[i] = 1; //Lis can be 1 current element
            for(int j=0;j<=i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }



         //Lis using binary search o(nlogn) o(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bs = {nums[0]}; //bs array always remain sorted 
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            //find position to insert --> lower_bound
            auto it = lower_bound(bs.begin(),bs.end(),nums[i]);
            if(it==bs.end())
                bs.push_back(nums[i]);
            else
                bs[it-bs.begin()] = nums[i];    
            
        }
        return bs.size();
    }





    //Lcs method LCS(s,sort(s)); 
    //for this approach to work we need to remove the duplicates else it fails for test case
    //[7,7,7,7,7,7,7]
    int f(int n, int m, vector<int>& nums, vector<int>& temp,vector<vector<int>>& dp)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if(nums[i-1]==temp[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][m];
    }
    void removeDuplicates(vector<int>& temp)
    {
        set<int> st;
        for(auto i: temp)
            st.insert(i);
        temp.clear();
        for(auto i: st)
            temp.push_back(i);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        removeDuplicates(temp);
        int n = nums.size();
        int m = temp.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(n,m,nums,temp,dp);
    }