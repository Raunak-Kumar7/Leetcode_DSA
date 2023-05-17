    // LCS
    // Recursive Approach
    int lcs(int i, int j, vector<int>& nums1, vector<int>& nums2)
    {
        //Base Condition
        if(i<0 || j<0) return 0;
        
        //Recursive call;
        if(nums1[i]==nums2[j])
            return 1 + lcs(i-1,j-1,nums1,nums2);
        else
            return 0 + max(lcs(i-1,j,nums1,nums2),lcs(i,j-1,nums1,nums2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        return lcs(n1-1,n2-1,nums1,nums2);
    }


    // LCS
    // Memoized Approach
    int lcs(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp)
    {
        //Base Condition
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //Recursive call;
        if(nums1[i]==nums2[j])
            return dp[i][j] = 1 + lcs(i-1,j-1,nums1,nums2,dp);
        else
            return dp[i][j] = 0 + max(lcs(i-1,j,nums1,nums2,dp),lcs(i,j-1,nums1,nums2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return lcs(n1-1,n2-1,nums1,nums2,dp);
    }



    // LCS
    // Tabulation Approach Approach
    int lcs(int n1, int n2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp)
    {
        //already initialised to 0
        
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0)); //initialise 0 in tabulation (1 size greater than n1,n2)
        return lcs(n1,n2,nums1,nums2,dp);
    }


    // LCS
    // Tabulation Approach Approach(Space Optimised)
    int lcs(int n1, int n2, vector<int>& nums1, vector<int>& nums2)
    {
        //already initialised to 0
        vector<int> prev(n2+1,0); //only need 1 previous row
        for(int i=1;i<n1+1;i++)
        {
            vector<int> curr(n2+1);
            for(int j=1;j<n2+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = 0 + max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n2];
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        return lcs(n1,n2,nums1,nums2);
    }