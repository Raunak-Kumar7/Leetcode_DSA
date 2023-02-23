	//Problem is similar to LIS 
	//using Tabulation 2 approach
	// bitonic means first increasing then decreasing strictly (or it can be vice versa also (Check))
	int f(int n , vector<int>nums)
	{
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
	    vector<int> bitonic(n,1);
	    //LtoR
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[j] < nums[i] && dp1[j] + 1 > dp1[i])
	            {
	                dp1[i] = dp1[j]+1;
	            }
	        }
	    }
	    
	    //RtoL
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[j] < nums[i] && dp2[j]+1>dp2[i])
	            {
	                dp2[i] = dp2[j]+1;
	            }
	        }
	    }
	    //Bitonic Seq length
	    int maxi = 1;
	    for(int i=0;i<n;i++)
	    {
	        bitonic[i] = dp1[i] + dp2[i] -1;
	        maxi = max(maxi,bitonic[i]);
	    }
	    return maxi;
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    return f(n , nums);
	}